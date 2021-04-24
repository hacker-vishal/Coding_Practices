using System.Runtime.Serialization;
using System.ServiceModel;

namespace ContractLib
{
    [DataContract]
    public class Math
    {
        public float addwork(float x, float y)
        {
            return (x + y);
        }

        public float subwork(float x, float y)
        {
            return (x - y);
        }

        public float multwork(float x, float y)
        {
            return (x * y);
        }

        public float divwork(float x, float y)
        {
            return (x / y);
        }
    }

    [ServiceContract]
    public interface IMathService
    {
        [OperationContract]
        float addwork(float x, float y);
        [OperationContract]
        float subwork(float x, float y);
        [OperationContract]
        float multwork(float x, float y);
        [OperationContract]
        float divwork(float x, float y);
    }
}
