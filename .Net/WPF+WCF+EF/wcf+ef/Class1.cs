using ContractLibrary;
using System.Collections.Generic;
using System.Linq;

namespace ServiceLibrary
{
    public class MyService : IServ
    {
        DacDB1Entities ent = new DacDB1Entities();
        public void AddPerson()
        {
            Employee emp = new Employee() { EmpID = 4, EmpName = "Dhoni", EmpDept = 20 };
            ent.Employees.Add(emp);
            ent.SaveChanges();
            ent.Dispose();
        }

        public bool ChangePersonInfo(Person per)
        {
            throw new System.NotImplementedException();
        }

        public List<Person> GetPeople()
        {
            List<Person> l = new List<Person>();
            //var emps = ent.Employees;
            var lstUsr = from k in ent.Employees select k;
            foreach (var item in lstUsr)
            {
                var per = new Person() { ID = item.EmpID, Name = item.EmpName, Job = (int)item.EmpDept };
                l.Add(per);
            }
            ent.Dispose();
            return l;
        }

        public Person GetPerson(int id)
        {
            var em = (from n in ent.Employees where n.EmpID == id select n).First();
            var per = new Person() { ID = em.EmpID, Name = em.EmpName, Job = (int)em.EmpDept };
            ent.SaveChanges();
            ent.Dispose();
            return per;
        }

        public bool ReleasePerson(Person per)
        {
            throw new System.NotImplementedException();
        }
    }
}
