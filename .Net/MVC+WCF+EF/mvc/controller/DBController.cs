using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Web.Mvc;
using WebAppWithSagar.Models;
using WebAppWithSagar.MVCServRef;

namespace WebAppWithSagar.Controllers
{
    public class DBController : Controller
    {
        ServClient serv = new ServClient();
        // GET: DB
        public ActionResult Index()
        { 
            return View();
        }

        public ActionResult MenuPartial()
        {
            return View();
        }

        public ActionResult AddPerson()
        {
            return View();
        }

        [HttpPost]
        public ActionResult AddPerson(People ppl)
        {
            serv.AddPerson(new Person() { ID = ppl.Id, Name = ppl.Name, Job = ppl.Job });
            return RedirectToAction("GetPeople");
        }

        public ActionResult RemovePerson()
        {
            return View();
        }

        [HttpPost]
        public ActionResult RemovePerson(int id)
        {
            serv.ReleasePerson(id);
            return RedirectToAction("GetPeople");
        }

        public ActionResult ChangePersonInfo()
        {
            return View();
        }

        [HttpPost]
        public ActionResult ChangePersonInfo(People ppl)
        {
            serv.ChangePersonInfo(new Person() { ID = ppl.Id, Name = ppl.Name, Job = ppl.Job });
            return RedirectToAction("GetPeople");
        }

        public ActionResult SearchPeople()
        {
            People ppl = new People() { Name = "0" };
            return View(ppl);
        }

        [HttpPost]
        public ActionResult SearchPeople(int id)
        {
            var per = serv.GetPerson(id);
            People ppl = new People() { Id = per.ID, Name = per.Name, Job = per.Job };
            return View("SearchPeople", ppl);
        }

        public ActionResult GetPeople()
        {
            var l = serv.GetPeople();

            List<People> lst = new List<People>();
            foreach(var item in l)
            {
                People p = new People() { Id = item.ID, Name = item.Name, Job = item.Job };
                lst.Add(p);
            }

            return View(lst);
        }
    }
}