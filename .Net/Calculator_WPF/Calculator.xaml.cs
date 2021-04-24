using System.Windows;

namespace WpfAppDac
{
    /// <summary>
    /// Interaction logic for Calculator.xaml
    /// </summary>
    public partial class Calculator : Window
    {
        public Calculator()
        {
            InitializeComponent();
        }

        private void AddFun(object sender, RoutedEventArgs e)
        {
            int x = int.Parse(fin.Text);
            int y = int.Parse(sin.Text);
            int z = x + y;
            result.Text = z.ToString();
        }

        private void SubFun(object sender, RoutedEventArgs e)
        {
            int x = int.Parse(fin.Text);
            int y = int.Parse(sin.Text);
            int z = x - y;
            result.Text = z.ToString();
        }
    }
}
