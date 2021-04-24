using System;
using System.IO.Pipes;

namespace Assign.net
{
    class greed
    {
        static void Main(string[] args)
        {
            for (int i = 4; i < 1000; i++)
            {
                int a = i;
                int m = i;
                int ans = 0;
                if (m == ((3*(a / 3)) + 1))
                {
                    m = (2 * m) / 3;
                    a = m;
                    if(m == ((3 * (a / 3)) + 1))
                    {
                        m = (2 * m) / 3;
                        a = m;
                        if((m == (3 * (a / 3)) + 1))
                        {
                            m = (2 * m) / 3;
                            a = m;
                            if (m==(3*(a/3)))
                            {
                                ans = i;
                                Console.WriteLine(ans);
                            }
                        }
                    }
                }
            }
        }
    }
}