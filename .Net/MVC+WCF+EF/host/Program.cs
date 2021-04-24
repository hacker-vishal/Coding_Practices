using ServiceLib;
using System;
using System.ServiceModel;

namespace HostApp
{
    class Program
    {
        static void Main(string[] args)
        {
            using (ServiceHost host = new ServiceHost(typeof(MyService)))
            {
                host.Open();
                Console.WriteLine("Server Started ...");
                Console.WriteLine("Press a key...");
                Console.ReadLine();
                Console.WriteLine("Server shutdown ...");
            }
        }
    }
}
