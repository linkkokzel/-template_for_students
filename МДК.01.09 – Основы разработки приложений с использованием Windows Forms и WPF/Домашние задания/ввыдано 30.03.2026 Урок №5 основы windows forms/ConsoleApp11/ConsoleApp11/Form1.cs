using System;
using System.Drawing;
using System.Windows.Forms;

namespace TaxiApp
{
    public partial class Form1 : Form
    {
        Label labelTitle;
        Label labelFrom;
        TextBox textFrom;

        Label labelTo;
        TextBox textTo;

        Label labelTariff;
        ComboBox comboTariff;

        Button buttonOrder;

        public Form1()
        {
            this.Text = "Заказ Такси";
            this.Size = new Size(350, 400);
            this.StartPosition = FormStartPosition.CenterScreen;

            labelTitle = new Label();
            labelTitle.Text = "Оформление заказа";
            labelTitle.Font = new Font("Arial", 14, FontStyle.Bold);
            labelTitle.Location = new Point(20, 20);
            labelTitle.Size = new Size(300, 30);
            this.Controls.Add(labelTitle);

            labelFrom = new Label();
            labelFrom.Text = "Откуда (Адрес):";
            labelFrom.Location = new Point(20, 70);
            labelFrom.Size = new Size(150, 20);
            this.Controls.Add(labelFrom);

            textFrom = new TextBox();
            textFrom.Location = new Point(20, 95);
            textFrom.Size = new Size(280, 20);
            this.Controls.Add(textFrom);

            labelTo = new Label();
            labelTo.Text = "Куда (Адрес):";
            labelTo.Location = new Point(20, 135);
            labelTo.Size = new Size(150, 20);
            this.Controls.Add(labelTo);

            textTo = new TextBox();
            textTo.Location = new Point(20, 160);
            textTo.Size = new Size(280, 20);
            this.Controls.Add(textTo);

            labelTariff = new Label();
            labelTariff.Text = "Выберите тариф:";
            labelTariff.Location = new Point(20, 200);
            labelTariff.Size = new Size(150, 20);
            this.Controls.Add(labelTariff);

            comboTariff = new ComboBox();
            comboTariff.Location = new Point(20, 225);
            comboTariff.Size = new Size(280, 20);
            comboTariff.Items.Add("Эконом");
            comboTariff.Items.Add("Комфорт");
            comboTariff.Items.Add("Бизнес");
            comboTariff.SelectedIndex = 0; 
            this.Controls.Add(comboTariff);

            buttonOrder = new Button();
            buttonOrder.Text = "Вызвать такси";
            buttonOrder.Location = new Point(20, 280);
            buttonOrder.Size = new Size(280, 40);
            buttonOrder.BackColor = Color.Yellow;
            buttonOrder.Font = new Font("Arial", 10, FontStyle.Bold);

            buttonOrder.Click += new EventHandler(КнопкаЗаказа_Клик);

            this.Controls.Add(buttonOrder);
        }

        private void КнопкаЗаказа_Клик(object sender, EventArgs e)
        {
            if (textFrom.Text == "" || textTo.Text == "")
            {
                MessageBox.Show("Пожалуйста, заполните адреса откуда и куда вы едете!", "Ошибка");
            }
            else
            {
                string сообщение = "Машина выехала!\nОткуда: " + textFrom.Text +
                                   "\nКуда: " + textTo.Text +
                                   "\nТариф: " + comboTariff.SelectedItem.ToString();

                MessageBox.Show(сообщение, "Успех!");
            }
        }
    }
}