﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class CheckOut : System.Web.UI.Page
{
    protected void btnContinue_Click(object sender, EventArgs e)
    {
        //if (Page.IsValid)
        //{
            //DateTime expiry = DateTime.Now.AddMinutes(5);
            //this.SetResponseCookie("FirstName", txtFirstName.Text, expiry);
            //this.SetResponseCookie("LastName", txtLastName.Text, expiry);
        //}
        this.LoadCustomerData();
        Response.Redirect("~/Order.aspx");
    }
    private void SetResponseCookie(string name, string value,
                                   DateTime expiry)
    {
        HttpCookie cookie = new HttpCookie(name, value);
        cookie.Expires = expiry;
        Response.Cookies.Add(cookie);
    }
    protected void Page_Load(object sender, EventArgs e)
    {
        //if (Request.Cookies["FirstName"] != null)
        //    txtFirstName.Text = Request.Cookies["FirstName"].Value;
        //if (Request.Cookies["LastName"] != null)
        //    txtLastName.Text = Request.Cookies["LastName"].Value;

        //get entry data from session state
        if (!IsPostBack)
        {
            string firstName = (string)Session["FirstName"];
            if (firstName != null) txtFirstName.Text = (string)Session["FirstName"];
            string lastName = (string)Session["LastName"];
            if (lastName != null) txtLastName.Text = (string)Session["LastName"];
            txtFirstName.Focus();
        }
    }

    private void LoadCustomerData()
    {
        //load data in session state object
        Session["FirstName"] = txtFirstName.Text;
        Session["LastName"] = txtLastName.Text;
    }

}