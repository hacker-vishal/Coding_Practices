using System;

namespace Assign.net
{
    class primes
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Num 1: ");
            int a = int.Parse(Console.ReadLine());

            Console.WriteLine("Num 2: ");
            int b = Convert.ToInt32(Console.ReadLine());

            int i, flag;

            Console.WriteLine("Prime numbers from " + a + " to " + b + " are: ");

            while (a < b)
            {
                if (a != 0 && a != 1)
                {
                    flag = 0;

                    for (i = 2; i <= a / 2; ++i)
                    {
                        if (a % i == 0)
                        {
                            flag = 1;
                            break;
                        }
                    }

                    if (flag == 0)
                        Console.WriteLine(a);
                }
                ++a;
            }
        }
    }
}