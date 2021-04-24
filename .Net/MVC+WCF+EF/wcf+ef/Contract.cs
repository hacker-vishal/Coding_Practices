using System.Collections.Generic;
using System.Runtime.Serialization;
using System.ServiceModel;

namespace ContractLib
{
    [DataContract]
    public class Person
    {
        [DataMember]
        public int ID { get; set; }
        [DataMember]
        public string Name { get; set; }
        [DataMember]
        public int Job { get; set; }
    }

    [ServiceContract]
    public interface IServ
    {
        [OperationContract]
        List<Person> GetPeople();
        [OperationContract]
        bool AddPerson(Person per);
        [OperationContract]
        bool ChangePersonInfo(Person per);
        [OperationContract]
        bool ReleasePerson(int id);
        [OperationContract]
        Person GetPerson(int id);
    }
}
