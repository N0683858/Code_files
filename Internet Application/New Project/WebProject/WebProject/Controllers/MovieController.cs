using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using WebProject.Models;

namespace WebProject.Controllers
{
    public class MovieController : Controller
    {
        // GET: Movie
        public ActionResult Recommended()
        {
            var movie = new Movie() { Name = "Sharek!" };
            return View(movie);
        }
    }
}