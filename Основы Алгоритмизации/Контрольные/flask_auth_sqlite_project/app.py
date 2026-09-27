from datetime import datetime, timezone
import os

from flask import Flask, redirect, render_template, url_for, session, flash
from flask_sqlalchemy import SQLAlchemy
from flask_session import Session
from flask_wtf import FlaskForm, CSRFProtect
from werkzeug.security import generate_password_hash, check_password_hash
from wtforms import StringField, PasswordField, SubmitField
from wtforms.validators import DataRequired, Email, Length, EqualTo

BASE_DIR = os.path.abspath(os.path.dirname(__file__))

app = Flask(__name__)
app.config["SECRET_KEY"] = os.environ.get(
    "SECRET_KEY", "change-this-secret-key-in-production"
)


app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///" + os.path.join(BASE_DIR, "users.db")
app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False

app.config["SQLALCHEMY_BINDS"] = {
    "sessions_bind": "sqlite:///" + os.path.join(BASE_DIR, "sessions.db")
}

db = SQLAlchemy(app)

app.config["SESSION_TYPE"] = "sqlalchemy"
app.config["SESSION_SQLALCHEMY"] = db
app.config["SESSION_SQLALCHEMY_TABLE"] = "sessions"
app.config["SESSION_SQLALCHEMY_BINDS"] = "sessions_bind"
app.config["SESSION_KEY_PREFIX"] = "session:"
app.config["SESSION_PERMANENT"] = True
app.config["PERMANENT_SESSION_LIFETIME"] = 60 * 60 * 24 * 7
app.config["SESSION_COOKIE_HTTPONLY"] = True
app.config["SESSION_COOKIE_SAMESITE"] = "Lax"

Session(app)
csrf = CSRFProtect(app)


class User(db.Model):
    __tablename__ = "users"

    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), unique=True, nullable=False, index=True)
    email = db.Column(db.String(255), unique=True, nullable=False, index=True)
    password_hash = db.Column(db.String(255), nullable=False)
    created_at = db.Column(
        db.DateTime, nullable=False, default=lambda: datetime.now(timezone.utc)
    )


class RegisterForm(FlaskForm):
    username = StringField(
        "Имя пользователя",
        validators=[DataRequired(), Length(min=3, max=80)],
    )
    email = StringField(
        "Email",
        validators=[DataRequired(), Email(), Length(max=255)],
    )
    password = PasswordField(
        "Пароль",
        validators=[DataRequired(), Length(min=6, max=128)],
    )
    password_confirm = PasswordField(
        "Повторите пароль",
        validators=[
            DataRequired(),
            EqualTo("password", message="Пароли должны совпадать."),
        ],
    )
    submit = SubmitField("Зарегистрироваться")


class LoginForm(FlaskForm):
    username = StringField(
        "Имя пользователя",
        validators=[DataRequired(), Length(max=80)],
    )
    password = PasswordField(
        "Пароль",
        validators=[DataRequired()],
    )
    submit = SubmitField("Войти")


def init_databases():
    with app.app_context():
        db.create_all()



def login_user(user: User):
    session.clear()
    session["user_id"] = user.id
    session.permanent = True


def get_current_user():
    user_id = session.get("user_id")
    if user_id is None:
        return None
    return db.session.get(User, user_id)


@app.route("/")
def index():
    if get_current_user():
        return redirect(url_for("profile"))
    return redirect(url_for("login"))


@app.route("/register", methods=["GET", "POST"])
def register():
    form = RegisterForm()

    if form.validate_on_submit():
        username = form.username.data.strip()
        email = form.email.data.strip().lower()

        if User.query.filter_by(username=username).first():
            form.username.errors.append("Такой username уже зарегистрирован.")
        elif User.query.filter_by(email=email).first():
            form.email.errors.append("Такой email уже зарегистрирован.")
        else:
            user = User(
                username=username,
                email=email,
                password_hash=generate_password_hash(form.password.data),
            )
            db.session.add(user)
            db.session.commit()

            login_user(user)
            flash("Регистрация выполнена успешно.", "success")
            return redirect(url_for("profile"))

    return render_template("register.html", form=form)


@app.route("/login", methods=["GET", "POST"])
def login():
    current_user = get_current_user()
    if current_user:
        return redirect(url_for("profile"))

    form = LoginForm()
    if form.validate_on_submit():
        username = form.username.data.strip()
        user = User.query.filter_by(username=username).first()

        if user and check_password_hash(user.password_hash, form.password.data):
            login_user(user)
            flash("Вы вошли в систему.", "success")
            return redirect(url_for("profile"))

        flash("Неверный username или пароль.", "error")

    return render_template("login.html", form=form)


@app.route("/profile")
def profile():
    user = get_current_user()
    if user is None:
        flash("Сначала войдите в систему.", "error")
        return redirect(url_for("login"))
    return render_template("profile.html", user=user)


@app.route("/logout", methods=["POST"])
def logout():
    session.clear()
    flash("Вы вышли из системы.", "success")
    return redirect(url_for("login"))


if __name__ == "__main__":
    init_databases()
    app.run(debug=True)
