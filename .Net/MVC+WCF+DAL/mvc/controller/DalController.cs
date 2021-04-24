using System.Web.Mvc;
using WebAppForDacBangalore.daldacservice;

namespace WebAppForDacBangalore.Controllers
{
    public class DalController : Controller
    {
        // GET: Dal
        public ActionResult Index()
        {
            DacClient x = new DacClient();
            ViewBag.Getppl = x.GetPeople();
            x.Close();
            return View();
        }
    }
}