using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Admin_CreateNewAdmin : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    Boolean register()
    {
        SqlConnection sqlConnection1 = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database.mdf;Integrated Security=True");

        sqlConnection1.Open();
        SqlCommand check_User_Name = new SqlCommand("SELECT COUNT(*) FROM [Users] WHERE ([Username] = @user)", sqlConnection1);
        check_User_Name.Parameters.AddWithValue("@user", username_tb.Text);
        int UserExist = (int)check_User_Name.ExecuteScalar();

        if (UserExist > 0)
        {
            //Username exist
            isUsernameValid.Text = "Username already exists!";
            return false;
        }
        else
        {
            //Username doesn't exist.
            //create new user data and store it in database 
            SqlCommand cmd = new SqlCommand();
            cmd.CommandType = System.Data.CommandType.Text;
            cmd.CommandText = "INSERT Users (Username, Password, SecurityQesAns, Role) VALUES (@username, @password, @security, @role)";
            //var role = "admin";
            cmd.Connection = sqlConnection1;

            cmd.Parameters.AddWithValue("@username", username_tb.Text);
            cmd.Parameters.AddWithValue("@password", password_tb.Text);
            cmd.Parameters.AddWithValue("@security", password_tb.Text);
            cmd.Parameters.AddWithValue("@role", userRoleCheckList.Text);
            cmd.ExecuteNonQuery();
            sqlConnection1.Close();

            return true;
        }



    }

    protected void register_btn_Click(object sender, EventArgs e)
    {

        if (Page.IsValid)
        {
            if (register())
            {
                msg_lbl.Text = "New user successfully created!";

            }
            else
            {
                msg_lbl.Text = "Failed to register new user!";
            }
        }

    }
}