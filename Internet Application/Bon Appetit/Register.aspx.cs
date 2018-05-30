using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Register : System.Web.UI.Page
{
    SqlConnection sqlConnection1 = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database.mdf;Integrated Security=True");
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    /*protected void CreateUserWizard1_CreatedUser(object sender, EventArgs e)
    {
        System.Data.SqlClient.SqlCommand cmd = new System.Data.SqlClient.SqlCommand();
        cmd.CommandType = System.Data.CommandType.Text;
        cmd.CommandText = "INSERT Users (Username, Password, Email) VALUES (@username, @password, @email)";
        cmd.Connection = sqlConnection1;



        sqlConnection1.Open();
        cmd.Parameters.AddWithValue("@username", );
        cmd.Parameters.AddWithValue("@password", password_tb.Text);
        cmd.ExecuteNonQuery();
        sqlConnection1.Close();
    }*/
}