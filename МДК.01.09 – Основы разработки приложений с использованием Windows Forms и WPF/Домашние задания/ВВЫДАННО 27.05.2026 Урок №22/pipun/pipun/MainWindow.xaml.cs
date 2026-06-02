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

using System;
using System.Windows;
using System.Windows.Controls;

namespace pipun
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            double a = 0;
            double b = 0;
            double area = 0;

            double.TryParse(tb1.Text, out a);
            double.TryParse(tb2.Text, out b);

            ComboBoxItem item = (ComboBoxItem)cbFigure.SelectedItem;

            if (item == null)
            {
                txtResult.Text = "Выберите фигуру";
                return;
            }

            string figure = item.Content.ToString();

            if (figure == "Квадрат")
            {
                area = a * a;
            }

            if (figure == "Прямоугольник")
            {
                area = a * b;
            }

            if (figure == "Круг")
            {
                area = 3.14 * a * a;
            }

            txtResult.Text = "Площадь = " + area;
        }
    }
}