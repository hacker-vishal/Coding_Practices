using System.Collections.Generic;
using System.Net.NetworkInformation;
using System.Windows;
using WpfAppEntityFramework.ServRef;

namespace WpfAppEntityFramework
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            getall();
            //getinfo();
            //addinfo();
        }

        void getall()
        {
            ServClient proxy = new ServClient();
            lstBx.ItemsSource = proxy.GetPeople();
            proxy.Close();
        }

        void getinfo()
        {
            ServClient proxy = new ServClient();
            List<Person> l = new List<Person>();
            l.Add(proxy.GetPerson(2));
            lstBx.ItemsSource = l;
            proxy.Close();
        }

        void addinfo()
        {
            ServClient proxy = new ServClient();
            proxy.AddPerson();
            proxy.Close();
        }
    }
}