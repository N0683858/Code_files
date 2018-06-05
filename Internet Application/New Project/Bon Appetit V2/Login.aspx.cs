using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Login : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        //get entry data from session state
        if (!IsPostBack)
        {
            string userame = (string)Session["Userame"];
            string password = (string)Session["Password"];
            string userRole = (string)Session["UserRole"];
        }
        
    }

    Boolean login()
    {
        SqlConnection sqlConnection1 = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database.mdf;Integrated Security=True");

        sqlConnection1.Open();
        SqlCommand check_User_Name = new SqlCommand("SELECT COUNT(*) FROM [Users] WHERE ([Username] = @user AND [Password] = @password)", sqlConnection1);
        check_User_Name.Parameters.AddWithValue("@user", username_tb.Text);
        check_User_Name.Parameters.AddWithValue("@password", password_tb.Text);
        int isValidUser = (int)check_User_Name.ExecuteScalar();
        
        if (isValidUser > 0)
        {
            //Username and Password match
            isUsernameValid.Text = "Username and Password match!";
            

            //load data in session state object
            this.LoadCustomerData();

            //Check if user is admin or a customer
            var role = "admin";
            SqlCommand checkUserRole = new SqlCommand("SELECT COUNT(*) FROM [Users] WHERE ([Username] = @user AND [Role] = @role)", sqlConnection1);
            checkUserRole.Parameters.AddWithValue("@user", username_tb.Text);
            checkUserRole.Parameters.AddWithValue("@role", role);
            int isAdmin = (int)checkUserRole.ExecuteScalar();
            if(isAdmin > 0)
            {
                Session["UserRole"] = role;

                msg_lbl.Text = "Admin Login Successfull!";
                ScriptManager.RegisterStartupScript(this, this.GetType(),"alert", "alert('" + msg_lbl.Text + "');window.location ='" + this.ResolveClientUrl("~/Admin/AdminHomePage.aspx") + "';", true);
                //Response.Redirect(this.ResolveClientUrl("~/Admin/AdminHomePage.aspx"));
            }
            else
            {
                Session["UserRole"] = "user";

                msg_lbl.Text = "User Login Successfull!";
                ScriptManager.RegisterStartupScript(this, this.GetType(), "alert", "alert('" + msg_lbl.Text + "');window.location ='" + this.ResolveClientUrl("~/Customers/CustHomePage.aspx") + "';", true);
                //Response.Redirect(this.ResolveClientUrl("~/Customers/CustHomePage.aspx"));
            }
            sqlConnection1.Close();
            return true;
            
        }
        else
        {
            //Username or password doesn't exist.
            isUsernameValid.Text = "Username or Password Incorrect!";
            return false;

        }

        

    }


    protected void Login_btn_Click(object sender, EventArgs e)
    {

        if (Page.IsValid)
        {
            if (login())
            {
                msg_lbl.Text = "Login Successfully!";

            }
            else
            {
                msg_lbl.Text = "Failed to Login!";
            }
        }

    }


    protected void cancel_btn_Click(object sender, EventArgs e)
    {
        Response.Redirect("~/index.aspx");
    }

    protected void forgotPass_btn_Click(object sender, EventArgs e)
    {
        Response.Redirect("~/ForgotPassword.aspx");
    }

    private void LoadCustomerData()
    {
        //load data in session state object
        Session["Username"] = username_tb.Text;
        Session["Password"] = password_tb.Text;
    }
}