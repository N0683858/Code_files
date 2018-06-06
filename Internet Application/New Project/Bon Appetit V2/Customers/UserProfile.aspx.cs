using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Customers_UserProfile : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        
        username_lbl2.Text = (string)Session["Username"];
        pass_lbl2.Text = (string)Session["Password"];
        role_lbl2.Text = (string)Session["UserRole"];

        
    }

    protected void logout_btn_Click(object sender, EventArgs e)
    {
        Session.RemoveAll();
        Response.Redirect("~/Login.aspx");
    }
}