using System.Windows;
using WpfCalcWithRadio.MathServRef;

namespace WpfCalcWithRadio
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void checkforchecks(object sender, RoutedEventArgs e)
        {
            MathServiceClient m = new MathServiceClient();

            if(add.IsChecked==true)
            {
                float a = float.Parse(fn.Text);
                float b = float.Parse(sn.Text);
                float res = m.addwork(a, b);
                result.Text = res.ToString();
            }

            else if(sub.IsChecked == true)
            {
                float a = float.Parse(fn.Text);
                float b = float.Parse(sn.Text);
                float res = m.subwork(a, b);
                result.Text = res.ToString();
            }

            else if(mult.IsChecked == true)
            {
                float a = float.Parse(fn.Text);
                float b = float.Parse(sn.Text);
                float res = m.multwork(a, b);
                result.Text = res.ToString();
            }

            else
            {
                float a = float.Parse(fn.Text);
                float b = float.Parse(sn.Text);
                float res = m.divwork(a, b);
                result.Text = res.ToString();
            }
        }
    }
}
