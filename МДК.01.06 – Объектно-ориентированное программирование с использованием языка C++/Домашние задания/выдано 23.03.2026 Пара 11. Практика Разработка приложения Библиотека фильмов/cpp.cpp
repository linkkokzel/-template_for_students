
-Поиск фильма по названию;
-Редактирование фильма;
-Фильтрация фильмов по жанру.
* /

#include <iostream>
#include <vector>

using namespace std;

class Movie {
public:
   
    Movie(string title, string genre, double rating, int duration) {
        this->title = title;
        this->genre = genre;
        this->rating = rating;
        this->duration = duration;
    }

    string getTitle() { return title; }
    string getGenre() { return genre; }
    double getRating() { return rating; }
    int getDuration() { return duration; }

    void setTitle(string title) { this->title = title; }
    void setGenre(string genre) { this->genre = genre; }
    void setRating(double rating) { this->rating = rating; }
    void setDuration(int duration) { this->duration = duration; }

    void display() {
        cout << "\nНазвание: " << title
            << "\nЖанр: " << genre
            << "\nРейтинг: " << rating
            << "\nДлительность: " << duration << " мин."
            << "\n-----------------------------\n";
    }

private:
    string title;
    string genre;
    double rating;
    int duration;
};

class Catalog {
public:

    void addMovie(string title, string genre, double rating, int duration) {
        movies.push_back(Movie(title, genre, rating, duration));
        cout << "Фильм успешно добавлен!\n";
    }

    void removeMovie(string title) {
        for (int i = 0; i < movies.size(); i++) {
            if (movies[i].getTitle() == title) {
                movies.erase(movies.begin() + i);
                cout << "Фильм удалён!\n";
                return;
            }
        }

        cout << "Фильм не найден!\n";
    }

    void findByTitle(string title) {
        bool found = false;

        for (Movie movie : movies) {
            if (movie.getTitle() == title) {
                movie.display();
                found = true;
            }
        }

        if (!found) {
            cout << "Фильм не найден!\n";
        }
    }

    void editMovie(string title) {
        for (int i = 0; i < movies.size(); i++) {

            if (movies[i].getTitle() == title) {

                string newTitle;
                string newGenre;
                double newRating;
                int newDuration;

                cout << "Новое название: ";
                getline(cin, newTitle);

                cout << "Новый жанр: ";
                getline(cin, newGenre);

                cout << "Новый рейтинг: ";
                cin >> newRating;

                cout << "Новая длительность: ";
                cin >> newDuration;

                cin.ignore();

                movies[i].setTitle(newTitle);
                movies[i].setGenre(newGenre);
                movies[i].setRating(newRating);
                movies[i].setDuration(newDuration);

                cout << "Фильм успешно изменён!\n";
                return;
            }
        }

        cout << "Фильм не найден!\n";
    }

    void filterByGenre(string genre) {
        bool found = false;

        for (Movie movie : movies) {
            if (movie.getGenre() == genre) {
                movie.display();
                found = true;
            }
        }

        if (!found) {
            cout << "Фильмы данного жанра не найдены!\n";
        }
    }

    void showMovies() {

        if (movies.empty()) {
            cout << "Каталог пуст!\n";
            return;
        }

        for (Movie movie : movies) {
            movie.display();
        }
    }

private:
    vector<Movie> movies;
};

int main() {

    Catalog movies;
    int choice;

    do {

        cout << "\n====== Библиотека фильмов ======\n";
        cout << "1. Показать все фильмы\n";
        cout << "2. Добавить фильм\n";
        cout << "3. Найти фильм\n";
        cout << "4. Удалить фильм\n";
        cout << "5. Редактировать фильм\n";
        cout << "6. Фильтр по жанру\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {

        case 1:
            movies.showMovies();
            break;

        case 2: {
            string title, genre;
            double rating;
            int duration;

            cout << "Название: ";
            getline(cin, title);

            cout << "Жанр: ";
            getline(cin, genre);

            cout << "Рейтинг: ";
            cin >> rating;

            cout << "Длительность (мин): ";
            cin >> duration;

            cin.ignore();

            movies.addMovie(title, genre, rating, duration);
            break;
        }

        case 3: {
            string title;

            cout << "Введите название фильма: ";
            getline(cin, title);

            movies.findByTitle(title);
            break;
        }

        case 4: {
            string title;

            cout << "Введите название фильма: ";
            getline(cin, title);

            movies.removeMovie(title);
            break;
        }

        case 5: {
            string title;

            cout << "Введите название фильма для редактирования: ";
            getline(cin, title);

            movies.editMovie(title);
            break;
        }

        case 6: {
            string genre;

            cout << "Введите жанр: ";
            getline(cin, genre);

            movies.filterByGenre(genre);
            break;
        }

        case 0:
            cout << "Выход из программы...\n";
            break;

        default:
            cout << "Неверный пункт меню!\n";
        }

    } while (choice != 0);

    return 0;
}