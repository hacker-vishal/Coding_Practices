using System;


namespace Assign.net
{
    class strongnum
    {
        public int calcfact(int z)
        {
            int num = 1;

            for (int i = z; i > 0; i--)
            {
                num = num * i;
            }

            return num;
        }

        static void Main(string[] args)
        {
            strongnum ass = new strongnum();
            
            for (int i = 1; i < 100000; i++)
            {
                int a=0, b = 0, c = 0, d = 0, e = 0, f = 0;
                int check = 0;

                if (i < 10)
                {
                    a = i % 10;

                    check = ass.calcfact(a);
                }

                else if (i < 100)
                {
                    a = i % 10;
                    b = i/10;

                    check = (ass.calcfact(a) + ass.calcfact(b));
                }

                else if (i < 1000)
                {
                    a = i % 10;
                    b = (i/10)%10;
                    c = (i/100)%10;

                    check = (ass.calcfact(a) + ass.calcfact(b) + ass.calcfact(c));
                }

                else if (i < 10000)
                {
                    a = i % 10;
                    b = (i / 10) % 10;
                    c = (i / 100) % 10;
                    d = (i / 1000) % 10;

                    check = (ass.calcfact(a) + ass.calcfact(b) + ass.calcfact(c) + ass.calcfact(d));
                }

                else if (i < 100000)
                {
                    a = i % 10;
                    b = (i / 10) % 10;
                    c = (i / 100) % 10;
                    d = (i / 1000) % 10;
                    e = (i / 10000) % 10;

                    check = (ass.calcfact(a) + ass.calcfact(b) + ass.calcfact(c) + ass.calcfact(d) + ass.calcfact(e));
                }

                else
                {
                    a = i % 10;
                    b = (i / 10) % 10;
                    c = (i / 100) % 10;
                    d = (i / 1000) % 10;
                    e = (i / 10000) % 10;
                    f = (i / 100000) % 10;

                    check = (ass.calcfact(a) + ass.calcfact(b) + ass.calcfact(c) + ass.calcfact(d) + ass.calcfact(e) + ass.calcfact(f));
                }

                if (i == check)
                {
                    int ans = i;
                    Console.WriteLine("You got: "+ans);
                }
            }
        }
    }
}
