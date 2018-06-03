﻿using System;
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
            isUsernameValid.Text = "UserName and Password match!";
            return true;
            
        }
        else
        {
            //Username or password doesn't exist.
            isUsernameValid.Text = "Username or Password Incorrect!";
            return false;

        }

        sqlConnection1.Close();

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
}