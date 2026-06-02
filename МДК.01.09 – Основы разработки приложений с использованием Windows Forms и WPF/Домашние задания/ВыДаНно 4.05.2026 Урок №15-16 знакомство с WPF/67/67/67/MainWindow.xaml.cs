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

namespace _67
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            double sum = 0;
            double percent = 0;
            double years = 0;

            double.TryParse(tbSum.Text, out sum);
            double.TryParse(tbPercent.Text, out percent);
            double.TryParse(tbYears.Text, out years);

            double total = sum + (sum * percent / 100 * years);

            tbResult.Text =
                "Итоговая сумма: " + total +
                "\nПереплата: " + (total - sum);
        }
    }
}