using System;
using System.Data.SqlClient;
using System.Web.UI;

public partial class ForgotPassword : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
      

    }

    Boolean newPass()
    {
        SqlConnection sqlConnection1 = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database.mdf;Integrated Security=True");

        sqlConnection1.Open();
        SqlCommand check_User_Name = new SqlCommand("SELECT COUNT(*) FROM [Users] WHERE ([Username] = @user AND [SecurityQesAns] = @ans)", sqlConnection1);
        check_User_Name.Parameters.AddWithValue("@user", username_tb.Text);
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
            cmd.Parameters.AddWithValue("@username", username_tb.Text);
            cmd.ExecuteNonQuery();
            sqlConnection1.Close();

            msg_lbl.Text = "Password Changed!";
            ScriptManager.RegisterStartupScript(this, this.GetType(), "alert", "alert('" + msg_lbl.Text + "');window.location ='" + this.ResolveClientUrl("~/Login.aspx") + "';", true);
            return true;
            

        }
        else
        {
            //Username or password doesn't exist.
            isUsernameValid.Text = "Username or Answer Incorrect!";
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
        Response.Redirect("~/home.aspx");
    }

}