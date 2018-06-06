using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Admin_AddNewProducts : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
      
    }

    Boolean addProduct()
    {
        SqlConnection sqlConnection1 = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database.mdf;Integrated Security=True");

        sqlConnection1.Open();
        //create new user data and store it in database 
        SqlCommand cmd = new SqlCommand();
        cmd.CommandType = System.Data.CommandType.Text;
        cmd.CommandText = "INSERT Products (ProductID, Name, ShortDescription, LongDescription, CategoryID, ImageFile, UnitPrice, OnHand) VALUES (@proID, @name, @shortDes, @longDes, @catID, @imgFile, @unitPrice, @onHand)";
        cmd.Connection = sqlConnection1;

        string onHandPrice = onHand_tb.Text;

        cmd.Parameters.AddWithValue("@proID", productID_tb.Text);
        cmd.Parameters.AddWithValue("@name", name_tb.Text);
        cmd.Parameters.AddWithValue("@shortDes", shortDes_tb.Text);
        cmd.Parameters.AddWithValue("@longDes", longDes_tb.Text);
        cmd.Parameters.AddWithValue("@catID", catID_tb.Text);
        cmd.Parameters.AddWithValue("@imgFile", imgFile.FileName);
        cmd.Parameters.AddWithValue("@unitPrice", unitPrice_tb.Text);
        cmd.Parameters.AddWithValue("@onHand", Convert.ToInt32(onHandPrice));
        cmd.ExecuteNonQuery();
        sqlConnection1.Close();

        return true;
        

    } 

    protected void add_btn_Click(object sender, EventArgs e)
    {

         if (Page.IsValid)
         {
             if (addProduct())
             {
                 string msg = "Added Successfully!";
                 ScriptManager.RegisterStartupScript(this, this.GetType(), "alert", "alert('" + msg + "');window.location ='" + this.ResolveClientUrl("~/Admin/MaintenancePage.aspx") + "';", true);

             }
             else
             {
                 string msg = "Failed to Add!";
                ScriptManager.RegisterStartupScript(this, this.GetType(), "alert", "alert('" + msg + "');window.location ='" + this.ResolveClientUrl("~/Admin/MaintenancePage.aspx") + "';", true);
            }
         }
         
    }

    protected void cancel_btn_Click(object sender, EventArgs e)
    {
        Response.Redirect(this.ResolveClientUrl("~/Admin/MaintenancePage.aspx"));
    }

}