using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp1
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private double GetValue(string text)
        {
            double number;

            if (double.TryParse(text, out number))
            {
                return number;
            }

            return 0;
        }

        private void ButtonCalculate_Click(object sender, RoutedEventArgs e)
        {
            double mon = GetValue(tbMon.Text);
            double tue = GetValue(tbTue.Text);
            double wed = GetValue(tbWed.Text);
            double thu = GetValue(tbThu.Text);
            double fri = GetValue(tbFri.Text);
            double sat = GetValue(tbSat.Text);
            double sun = GetValue(tbSun.Text);

            double sum = mon + tue + wed + thu + fri + sat + sun;

            double average = sum / 7;

            double max = mon;

            if (tue > max) max = tue;
            if (wed > max) max = wed;
            if (thu > max) max = thu;
            if (fri > max) max = fri;
            if (sat > max) max = sat;
            if (sun > max) max = sun;

            txtResult.Text =
                "Общая сумма: " + sum +
                "\nСредний расход: " + average +
                "\nМаксимальный расход: " + max;
        }

        private void ButtonClear_Click(object sender, RoutedEventArgs e)
        {
            tbMon.Text = "";
            tbTue.Text = "";
            tbWed.Text = "";
            tbThu.Text = "";
            tbFri.Text = "";
            tbSat.Text = "";
            tbSun.Text = "";

            txtResult.Text = "";
        }
    }
}