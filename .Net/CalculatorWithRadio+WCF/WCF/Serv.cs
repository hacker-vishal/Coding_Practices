using ContractLib;
using System;

namespace ServLib
{
    public class CService : IMathService
    {
        public float addwork(float x, float y)
        {
            return x + y;
        }

        public float divwork(float x, float y)
        {
            return x / y;
        }

        public float multwork(float x, float y)
        {
            return x * y;
        }

        public float subwork(float x, float y)
        {
            return x - y;
        }
    }
}
