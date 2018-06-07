using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Admin_AdminMasterPage : System.Web.UI.MasterPage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        string username = (string)Session["Username"];
        string role = (string)Session["UserRole"];
        if ((username != null) && (role == "admin"))
        {
            lblwelcome_msg.Text = "Welcome back, " + (string)Session["Username"] + "!";
        }
        else
        {
            Response.Redirect("~/RestrictedPage.aspx");
        }
    }

    protected void logout_btn_Click(object sender, EventArgs e)
    {
        Session.RemoveAll();
        Response.Redirect("~/Login.aspx");
    }
}
