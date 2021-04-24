using ServLib;
using System;
using System.ServiceModel;

namespace Host
{
    class Host
    {
        static void Main(string[] args)
        {
            ServiceHost host = new ServiceHost(typeof(CService));
            host.Open();
            Console.WriteLine("Server started ....");
            Console.WriteLine("Press a key to continue...");
            Console.ReadLine();
            host.Close();
            Console.WriteLine("Server ShutDown ....");

        }
    }
}
