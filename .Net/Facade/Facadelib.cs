using Flib1;
using Flib2;
using System;

namespace Facadelib
{
    public class FClass
    {
        public void mathadd(int x, int y)
        {
            Func<int,int,int> add = AddSub.add;
           
            Console.WriteLine($"addition={add(x,y)}");
        }

        public void mathsub(int x, int y)
        {
            Func<int,int,int> sub = AddSub.sub;

            Console.WriteLine($"subtraction={sub(x,y)}");
        }

        public void mathmult(int x, int y)
        {
            Func<int, int, int> mul = MultDiv.mult;

            Console.WriteLine($"multiplication={mul(x, y)}");
        }

        public void mathdiv(int x, int y)
        {
            Func<float, float, float> div = MultDiv.div;

            Console.WriteLine($"division={div(x, y)}");
        }
    }
}
