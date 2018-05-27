using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using Database_Helpers;

public partial class LoginPage : System.Web.UI.Page
{
    helper db = new helper();

    protected void Page_Load(object sender, EventArgs e)
    {
        
    }

    Boolean register()
    {
        
        db.values.Add("Email", username_tb.Text);
        db.values.Add("Last Name", lastname_tb.Text);
        db.values.Add("First Name", firstname_tb.Text);
        db.values.Add("Password", password_tb.Text);

        if (db.insert("Customers",db.values))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    protected void register_btn_Click(object sender, EventArgs e)
    {
        if(register())
        {
            msg_lbl.Text = "Registered Successfully!";
        }
        else
        {
            msg_lbl.Text = "Failed to Register!";
        }
    }
}