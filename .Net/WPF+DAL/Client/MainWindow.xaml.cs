using System.ServiceModel.Security;
using System.Windows;
using WpfAppDalClient.ServiceReferenceDal;

namespace WpfAppDalClient
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

        DacClient proxy = new DacClient();

        private void getall(object sender, RoutedEventArgs e)
        {
            lstBx.ItemsSource = proxy.GetPeople();
            proxy.Close();
        }

        private void addonerecord(object sender, RoutedEventArgs e)
        {
            int x = int.Parse(t1.Text);
            string y = t2.Text;
            int z = int.Parse(t3.Text);

            Person p = new Person() ;

            sts.Text = (proxy.AddPerson(p)!=false?"insert successful":"insert failed");
            proxy.Close();
        }

        private void modifyrecord(object sender, RoutedEventArgs e)
        {

        }

        private void deleterecord(object sender, RoutedEventArgs e)
        {

        }
    }
}
