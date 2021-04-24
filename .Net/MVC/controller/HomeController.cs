using System.Collections.Generic;
using System.Web;
using System.Web.Mvc;
using WebAppDac.Models;

namespace WebAppDac.Controllers
{
    public class HomeController : Controller
    {
        // GET: Home
        public ActionResult Index()
        {
            Person person = new Person
            {
                PersonName="Sachin",
                City="Mumbai"
            };
            return View("PersonEdit",person);
        }
        //[HttpPost]
        //public ActionResult Index(Person per1,Person newPerson)
        //{
        //    return View("PersonDisplay", new[] { per1, newPerson });
        //}

        [HttpPost]
        public ActionResult Index(Person per1, [Bind(Prefix ="newPerson")]Person per2)
        {
            return View("PersonDisplay", new[] { per1, per2 });
        }
        //list of string
        public ActionResult Directors()
        {
            return View();
        }
        [HttpPost]
        public ActionResult Directors(List<string> music)
        {
            return View("DisplayMusic",music);
        }


        public ActionResult Register()
        {
            return View();
        }
        [HttpPost]
        public ActionResult Register(FormCollection formData)
        {
            //create the object using DI
            Person person = new Person();//use DI container kernet.get
            if(TryUpdateModel(person, formData))
            {
                //yes
            }
            else
            {
                //no
            }
            return View("PersonDisplay", new[] {person});
        }

        public ActionResult Upload()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Upload(HttpPostedFileBase myFile)
        {
            string fileName = @"E:\Ali\Company\abc";
            myFile.SaveAs(fileName);
            byte[] myBytes = new byte[myFile.ContentLength];
            myFile.InputStream.Read(myBytes, 0, myFile.ContentLength);
            return View();
        }

        public ActionResult lsppl()
        {
            List<Person> l = new List<Person>()
            {
                new Person(){PersonName="sagar",City="meerut"},
                new Person(){PersonName="ritesh",City="bangalore"},
                new Person(){PersonName="shubham",City="nanded"},
                new Person(){PersonName="dinesh",City="delhi"},
                new Person(){PersonName="rohan",City="kolhapur"}
            };
            return View(l);
        }

        /*[HttpPost]
        public ActionResult lsppl(List<Person> l)
        {
            return View("listpeople",l);
        }*/
    }
}