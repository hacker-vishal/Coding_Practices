using System;
using System.Configuration;
using System.Reflection;
using System.Windows;

namespace WpfAppCalcAddAssign
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Add(object sender, RoutedEventArgs e)
        {
            int x = int.Parse(fn.Text);
            int y = int.Parse(sn.Text);
            int res = CalcAddLib.Math.add(x, y);
            result.Text = res.ToString();
        }

        private void Sub(object sender, RoutedEventArgs e)
        {
            int x = int.Parse(fn.Text);
            int y = int.Parse(sn.Text);
            int res = CalcSubLib.Math.sub(x, y);
            result.Text = res.ToString();
        }

        private void Mult(object sender, RoutedEventArgs e)
        {
            int x = int.Parse(fn.Text);
            
            int y = int.Parse(sn.Text);

            string asmName = ConfigurationManager.AppSettings["asmKey"];
            
            Assembly asm = Assembly.Load(asmName);
            
            string typeName = ConfigurationManager.AppSettings["typKey"];
            
            Type t = asm.GetType(typeName);
            
            string methName = ConfigurationManager.AppSettings["methKey"];
            
            MethodInfo methinfo = t.GetMethod(methName);
            
            object obj = Activator.CreateInstance(t);
            
            object res = methinfo.Invoke(obj, new object[] {x,y});
            
            result.Text = res.ToString();
        }

        private void Div(object sender, RoutedEventArgs e)
        {
            double x = int.Parse(fn.Text);
            double y = int.Parse(sn.Text);
            double res = CalcDivLib.Math.div(x, y);
            result.Text = res.ToString();
        }
    }
}
