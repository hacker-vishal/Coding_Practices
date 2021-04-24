using ContractLib;
using System.Collections.Generic;
using System.Linq;

namespace ServiceLib
{
    public class MyService : IServ
    {
        DacDB1Entities ent = new DacDB1Entities();
        public bool AddPerson(Person per)
        {
            Employee emp = new Employee() { EmpID = per.ID, EmpName = per.Name, EmpDept = per.Job };
            ent.Employees.Add(emp);
            int sts = ent.SaveChanges();
            ent.Dispose();
            return sts > 0;
        }

        public bool ChangePersonInfo(Person per)
        {
            var emp = (from n in ent.Employees where n.EmpID == per.ID select n).First();
            emp.EmpName = per.Name;
            emp.EmpDept = per.Job;
            int sts = ent.SaveChanges();
            ent.Dispose();
            return sts > 0;
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

        public bool ReleasePerson(int id)
        {
            var em = (from n in ent.Employees where n.EmpID == id select n).First();
            ent.Employees.Remove(em);
            int sts = ent.SaveChanges();
            return sts > 0;
        }
    }
}
