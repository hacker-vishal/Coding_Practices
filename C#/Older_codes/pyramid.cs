using System;

namespace Assign.net
{
    class pyramid
    {
        static void Main(string[] args)
        {
            int x = 1;
            for (int i = 1; i <= 5; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    Console.Write(x);
                    x++;
                    x %= 10;
                }
                Console.WriteLine();
            }
        }
    }
}