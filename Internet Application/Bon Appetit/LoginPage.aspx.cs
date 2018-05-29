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
    SqlConnection sqlConnection1 = new SqlConnection("Data Source=(LocalDB)/MSSQLLocalDB;AttachDbFilename=|DataDirectory|/Database.mdf;Integrated Security=True");

    protected void Page_Load(object sender, EventArgs e)
    {
        
    }

   /* Boolean register()
    {
        string connetionString = null;
        string sql = null;
        connetionString = V;
        using (SqlConnection cnn = new SqlConnection(connetionString))
        {
            sql = "insert into Main ([Email], [Last Name], [First Name], [Password]) values(@email,@last,@first, @password)";
            cnn.Open();
            using (SqlCommand cmd = new SqlCommand(sql, cnn))
            {
                cmd.Parameters.AddWithValue("@first", username_tb.Text);
                cmd.Parameters.AddWithValue("@first", firstname_tb.Text);
                cmd.Parameters.AddWithValue("@last", lastname_tb.Text);
                cmd.Parameters.AddWithValue("@password", password_tb.Text);
                cmd.ExecuteNonQuery();
            }
        }

        if (V.insert("Customers", db.values))
        {
            return true;
        }
        else
        {
            return false;
        } */

        /*db.values.Add("Email", username_tb.Text);
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

    }*/

    protected void register_btn_Click(object sender, EventArgs e)
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

        /* string sql = null;
         string connetionString = V;
          using (SqlConnection cnn = new SqlConnection(V))
          {
              sql = "insert into Main ([Email], [Last Name], [First Name], [Password]) values(@email,@last,@first, @password)";
              cnn.Open();
              using (SqlCommand cmd = new SqlCommand(sql, cnn))
              {
                  cmd.Parameters.AddWithValue("@first", username_tb.Text);
                  cmd.Parameters.AddWithValue("@first", firstname_tb.Text);
                  cmd.Parameters.AddWithValue("@last", lastname_tb.Text);
                  cmd.Parameters.AddWithValue("@password", password_tb.Text);
                  cmd.ExecuteNonQuery();
              }
          }
          */

        /*  if (register())
          {
              msg_lbl.Text = "Registered Successfully!";
          }
          else
          {
              msg_lbl.Text = "Failed to Register!";
          } */
    }
    
}