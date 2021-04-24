using DAL;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;

namespace DacServiceLibrary
{
    //ORM
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
    public interface IDac
    {
        [OperationContract]
        List<Person> GetPeople();
        [OperationContract]
        bool AddPerson(Person per);
        [OperationContract]
        bool ChangePersonInfo(Person per);
        [OperationContract]
        bool ReleasePerson(Person per);
        [OperationContract]
        Person GetPerson(int id);
    }
    public class CDacService : IDac
    {
        IDAL dal;
        public CDacService()
        {
            string cnnstr = ConfigurationManager.ConnectionStrings["cnnStrKey"].ConnectionString;
            dal = DALFactory.GetDalFactory(cnnstr);
        }
        public bool AddPerson(Person per)
        {
            int affected = dal.InsertData(new DataOrm { DataID=per.ID, DataInfo=per.Name, DataKey=per.Job });
            return affected > 0;
        }

        public bool ChangePersonInfo(Person per)
        {
            int affected = dal.UpdateData(new DataOrm { DataID = per.ID, DataInfo = per.Name, DataKey = per.Job });
            return affected > 0;
        }

        public List<Person> GetPeople()
        {
            List<DataOrm> lstOrm= dal.GetAllData();
            List<Person> people = (from orm in lstOrm select new Person { ID = orm.DataID, Name = orm.DataInfo, Job = orm.DataKey }).ToList();
            return people;
        }

        public Person GetPerson(int id)
        {
            DataOrm orm=  dal.GetData(id);
            return new Person { ID = orm.DataID, Name = orm.DataInfo, Job = orm.DataKey };
        }

        public bool ReleasePerson(Person per)
        {
            int affected = dal.DeleteData(per.ID);
            return affected > 0;
        }
    }
}
