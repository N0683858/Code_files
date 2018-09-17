using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Customers_CustChangePass : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    Boolean newPass()
    {
        SqlConnection sqlConnection1 = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database.mdf;Integrated Security=True");
        string username = (string)Session["Username"];
        sqlConnection1.Open();
        SqlCommand check_User_Name = new SqlCommand("SELECT COUNT(*) FROM [Users] WHERE ([Username] = @user AND [SecurityQesAns] = @ans)", sqlConnection1);
        check_User_Name.Parameters.AddWithValue("@user", username);
        check_User_Name.Parameters.AddWithValue("@ans", ans_tb.Text);
        int isValidUser = (int)check_User_Name.ExecuteScalar();

        if (isValidUser > 0)
        {
            //Username and Security Answer match
            isUsernameValid.Text = "Security Question and Answer match!";

            SqlCommand cmd = new SqlCommand();
            cmd.CommandType = System.Data.CommandType.Text;
            cmd.CommandText = "UPDATE Users SET Password=@pass WHERE Username=@username";
            cmd.Connection = sqlConnection1;
            cmd.Parameters.AddWithValue("@pass", password_tb.Text);
            cmd.Parameters.AddWithValue("@username", username);
            cmd.ExecuteNonQuery();
            sqlConnection1.Close();

            Session["Password"] = password_tb.Text;//update pass in session object too
            msg_lbl.Text = "Password Changed!";
            ScriptManager.RegisterStartupScript(this, this.GetType(), "alert", "alert('" + msg_lbl.Text + "');window.location ='" + this.ResolveClientUrl("~/Customers/UserProfile.aspx") + "';", true);
            return true;


        }
        else
        {
            //Username or password doesn't exist.
            isUsernameValid.Text = "Security Answer Incorrect!";
            return false;


        }


    }


    protected void continue_btn_Click(object sender, EventArgs e)
    {

        if (Page.IsValid)
        {
            if (newPass())
            {
                msg_lbl.Text = "Data match!";

            }
            else
            {
                msg_lbl.Text = "Data does not match!";
            }
        }

    }


    protected void cancel_btn_Click(object sender, EventArgs e)
    {
        Response.Redirect(this.ResolveClientUrl("~/Customers/UserProfile.aspx"));
    }

}