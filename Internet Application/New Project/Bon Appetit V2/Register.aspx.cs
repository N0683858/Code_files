using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Register : System.Web.UI.Page
{

    // private const string V = "Data Source=(LocalDB)MSSQLLocalDB;AttachDbFilename=|DataDirectory|Database.mdf;Integrated Security=True";
    

    protected void Page_Load(object sender, EventArgs e)
    {

    }

    Boolean register()
    {
        SqlConnection sqlConnection1 = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database.mdf;Integrated Security=True");
         SqlCommand cmd = new SqlCommand();
         cmd.CommandType = System.Data.CommandType.Text;
         cmd.CommandText = "INSERT Users (Username, Password, SecurityQesAns) VALUES (@username, @password, @security)";
         cmd.Connection = sqlConnection1;



         sqlConnection1.Open();
         cmd.Parameters.AddWithValue("@username", username_tb.Text);
         cmd.Parameters.AddWithValue("@password", password_tb.Text);
         cmd.Parameters.AddWithValue("@security", security_tb.Text);
         cmd.ExecuteNonQuery();
         sqlConnection1.Close();
         

       /* SqlCommand check_User_Name = new SqlCommand("SELECT COUNT(*) FROM [Users] WHERE ([username] = @user)", sqlConnection1);
        check_User_Name.Parameters.AddWithValue("@user", username_tb.Text);
        int UserExist = (int)check_User_Name.ExecuteScalar();

        if (UserExist > 0)
        {
            //Username exist
            isUsernameValid.Text = "Username already exists!";
        }
        else
        {
            //Username doesn't exist.
            SqlCommand cmd = new SqlCommand();
            cmd.CommandType = System.Data.CommandType.Text;
            cmd.CommandText = "INSERT Users (Username, Password, SecurityAns) VALUES (@username, @password, @security)";
            cmd.Connection = sqlConnection1;



            sqlConnection1.Open();
            cmd.Parameters.AddWithValue("@username", username_tb.Text);
            cmd.Parameters.AddWithValue("@password", password_tb.Text);
            cmd.Parameters.AddWithValue("@security", password_tb.Text);
            cmd.ExecuteNonQuery();
            sqlConnection1.Close();
        }  */

        return true;

    }

    protected void register_btn_Click(object sender, EventArgs e)
    {

        /*System.Data.SqlClient.SqlCommand cmd = new System.Data.SqlClient.SqlCommand();
         cmd.CommandType = System.Data.CommandType.Text;
         cmd.CommandText = "INSERT Customers (Email, LastName, FirstName, Password) VALUES (@email, @last, @first, @password)";
         cmd.Connection = sqlConnection1;



         sqlConnection1.Open();
         cmd.Parameters.AddWithValue("@email", username_tb.Text);
         cmd.Parameters.AddWithValue("@first", firstname_tb.Text);
         cmd.Parameters.AddWithValue("@last", lastname_tb.Text);
         cmd.Parameters.AddWithValue("@password", password_tb.Text);
         cmd.ExecuteNonQuery();
         sqlConnection1.Close(); */

        if (Page.IsValid)
        {
            if (register())
            {
                msg_lbl.Text = "Registered Successfully!";
            }
            else
            {
                msg_lbl.Text = "Failed to Register!";
            }
        }
        
    }
}