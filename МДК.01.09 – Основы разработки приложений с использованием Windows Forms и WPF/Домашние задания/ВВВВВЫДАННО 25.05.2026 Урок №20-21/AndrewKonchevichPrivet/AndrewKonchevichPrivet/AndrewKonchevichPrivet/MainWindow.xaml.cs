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
using System.Collections.Generic;
using System.Windows;
// ✨ПИРОГ✨ это просто название приложения 
// AndrewKonchevichPrivet это просто название данного пороекта 
namespace AndrewKonchevichPrivet
{
    public partial class MainWindow : Window
    {
        List<string> titles = new List<string>();      
        List<string> contents = new List<string>();    

        public MainWindow()
        {
            InitializeComponent();
        }

       
        private void AddBtn_Click(object sender, RoutedEventArgs e)
        {

            if (TitleBox.Text == "")
            {
                MessageBox.Show("Введите заголовок!", "Ошибка");
                return;
            }

            if (ContentBox.Text == "")
            {
                MessageBox.Show("Введите текст заметки!", "Ошибка");
                return;
            }

            titles.Add(TitleBox.Text);
            contents.Add(ContentBox.Text);

            UpdateList();

            ClearFields();

            MessageBox.Show("Заметка добавлена!", "Готово");
        }

        private void ClearBtn_Click(object sender, RoutedEventArgs e)
        {
            ClearFields();
        }

        private void ClearFields()
        {
            TitleBox.Text = "";
            ContentBox.Text = "";
            TitleBox.Focus();
        }

        private void UpdateList()
        {
            NotesList.Items.Clear();
            for (int i = 0; i < titles.Count; i++)
            {
                string preview = titles[i];
                if (contents[i].Length > 30)
                    preview += " - " + contents[i].Substring(0, 30) + "...";
                else
                    preview += " - " + contents[i];

                NotesList.Items.Add(preview);
            }
        }

        private void NotesList_SelectionChanged(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
        {
            int index = NotesList.SelectedIndex;
            if (index >= 0 && index < titles.Count)
            {
                TitleBox.Text = titles[index];
                ContentBox.Text = contents[index];
            }
        }
    }
}
