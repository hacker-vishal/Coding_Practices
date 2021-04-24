using System.Collections.Generic;
using System.Runtime.Serialization;
using System.ServiceModel;

namespace ContractLibrary
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
        void AddPerson();
        [OperationContract]
        bool ChangePersonInfo(Person per);
        [OperationContract]
        bool ReleasePerson(Person per);
        [OperationContract]
        Person GetPerson(int id);
    }
}
