using System;
using System.ServiceModel;

namespace DacDataHost
{
    class Program
    {
        static void Main(string[] args)
        {
            using (ServiceHost host = new ServiceHost(typeof(DacServiceLibrary.CDacService)))
            {
                host.Open();
                Console.WriteLine("Server Started ...");
                Console.WriteLine("Press akey...");
                Console.ReadLine();
                Console.WriteLine("Server shutdown ...");
            }
        }
    }
}
