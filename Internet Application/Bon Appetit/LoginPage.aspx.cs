using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using Database_Helpers;

public partial class LoginPage : System.Web.UI.Page
{
    // private const string V = "Data Source=(LocalDB)MSSQLLocalDB;AttachDbFilename=|DataDirectory|Database.mdf;Integrated Security=True";
    SqlConnection sqlConnection1 = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database.mdf;Integrated Security=True");
    
    protected void Page_Load(object sender, EventArgs e)
    {
        
    }

    Boolean register()
    {
        System.Data.SqlClient.SqlCommand cmd = new System.Data.SqlClient.SqlCommand();
        cmd.CommandType = System.Data.CommandType.Text;
        cmd.CommandText = "INSERT Customers (Email, LastName, FirstName, Password) VALUES (@email, @last, @first, @password)";
        cmd.Connection = sqlConnection1;



        sqlConnection1.Open();
        cmd.Parameters.AddWithValue("@email", username_tb.Text);
        cmd.Parameters.AddWithValue("@first", firstname_tb.Text);
        cmd.Parameters.AddWithValue("@last", lastname_tb.Text);
        cmd.Parameters.AddWithValue("@password", password_tb.Text);
        cmd.ExecuteNonQuery();
        sqlConnection1.Close();


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