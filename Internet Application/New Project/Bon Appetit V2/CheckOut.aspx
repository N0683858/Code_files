﻿<%@ Page Title="" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="CheckOut.aspx.cs" Inherits="CheckOut" %>
<%@ MasterType VirtualPath="~/Site.master" %>

<asp:Content ID="headContent" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
    
</asp:Content>

<asp:Content ID="formContent" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <h1>CheckOut</h1>
    
        <h2>Contact information</h2>
        <label>Email address: </label>
        <asp:TextBox ID="txtEmail1" runat="server" CssClass="entry" TextMode="Email"></asp:TextBox> 
            <asp:RequiredFieldValidator ID="rfvEmail1" runat="server" 
                ErrorMessage="Email is required" CssClass="validator" 
                Display="Dynamic" ControlToValidate="txtEmail1">
            </asp:RequiredFieldValidator>          
        <br />
        <label>Email Re-entry: </label>
        <asp:TextBox ID="txtEmail2" runat="server" CssClass="entry" ></asp:TextBox> 
            <asp:RequiredFieldValidator ID="rfvEmail2" runat="server" 
                ErrorMessage="Email is required" CssClass="validator" 
                Display="Dynamic" ControlToValidate="txtEmail2">
            </asp:RequiredFieldValidator>          
        <br />
        <label>First Name: </label>
        <asp:TextBox ID="txtFirstName" runat="server" CssClass="entry"></asp:TextBox>  
            <asp:RequiredFieldValidator ID="rfvFirstName" runat="server" 
                ErrorMessage="First name is required" CssClass="validator" 
                Display="Dynamic" ControlToValidate="txtFirstName">
            </asp:RequiredFieldValidator>
            <br />          
        <label>Last Name: </label>
        <asp:TextBox ID="txtLastName" runat="server" CssClass="entry"></asp:TextBox>
            <asp:RequiredFieldValidator ID="rfvLastName" runat="server" 
                ErrorMessage="Last name is required" CssClass="validator" 
                Display="Dynamic" ControlToValidate="txtLastName">
            </asp:RequiredFieldValidator>
            <br />
        <label>Phone Number:</label>
        <asp:TextBox ID="txtPhone" runat="server" CssClass="entry" TextMode="Phone"></asp:TextBox>
        <asp:RequiredFieldValidator ID="rfvPhoneNumber" runat="server" 
            ErrorMessage="Phone number is required." CssClass="validator"
            Display="Dynamic" ControlToValidate="txtPhone"></asp:RequiredFieldValidator><br />

        <h2>Billing address</h2>
        <label>Address: </label>
        <asp:TextBox ID="txtAddress" runat="server" CssClass="entry"></asp:TextBox>       
            <asp:RequiredFieldValidator ID="rfvStreetAddress" runat="server" 
                ErrorMessage="Street Address is required" CssClass="validator" 
                Display="Dynamic" ControlToValidate="txtAddress"></asp:RequiredFieldValidator>   
            <br />
        <label>City: </label><asp:TextBox ID="txtCity" runat="server" CssClass="entry"></asp:TextBox>  
            <asp:RequiredFieldValidator ID="rfvCity" runat="server" 
                ErrorMessage="City is required" CssClass="validator" 
                Display="Dynamic" ControlToValidate="txtCity"></asp:RequiredFieldValidator>        
            <br />
        <label>State: </label>
        <asp:DropDownList ID="ddlState" runat="server" CssClass="entry" 
            AppendDataBoundItems="True" DataSourceID="SqlDataSource1" 
            DataTextField="StateName" DataValueField="StateCode">
            <asp:ListItem Text="" Value="" Selected="True"></asp:ListItem>
        </asp:DropDownList>
            <asp:RequiredFieldValidator ID="rfvState" runat="server" 
                ErrorMessage="State is required" CssClass="validator" 
                Display="Dynamic" ControlToValidate="ddlState">
            </asp:RequiredFieldValidator><br />
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConnectionString="<%$ ConnectionStrings:Database %>" 
            SelectCommand="SELECT [StateCode], [StateName] FROM [States] ORDER BY [StateCode]">
        </asp:SqlDataSource>
        <label>Zip code: </label>
        <asp:TextBox ID="txtZip" runat="server" CssClass="entry" MaxLength="5">
        </asp:TextBox>    
            <asp:RequiredFieldValidator ID="rfvZip" runat="server" 
                ErrorMessage="Zip is required" CssClass="validator" 
                Display="Dynamic" ControlToValidate="txtZip">
            </asp:RequiredFieldValidator><br />
        <h2>Optional data</h2>
        <div id="optionalData">
            Please let me know about:
            <asp:CheckBoxList ID="cblAboutList"  runat="server" RepeatColumns="2">
                <asp:ListItem Value="New" Selected="True">New products</asp:ListItem>
                <asp:ListItem Value="Special">Special offers</asp:ListItem>
                <asp:ListItem Value="Revisions">New editions</asp:ListItem>
                <asp:ListItem Value="Local">Local events</asp:ListItem>
            </asp:CheckBoxList>
            Please contact me via:<br />
            <br />
            <asp:ListBox ID="lstContactVia" runat="server" SelectionMode="Multiple">
                <asp:ListItem Selected="True">Twitter</asp:ListItem>
                <asp:ListItem>Facebook</asp:ListItem>
                <asp:ListItem>Text Message</asp:ListItem>
                <asp:ListItem>Email</asp:ListItem>
            </asp:ListBox>
            <br />
            <br />
        </div>
            
        <asp:Button ID="btnCheckOut" runat="server" Text="Check Out" CssClass="button" 
            OnClick="btnCheckOut_Click"  />
        <asp:Button ID="btnCancel" runat="server" Text="Cancel Order" 
            CausesValidation="False" OnClick="btnCancel_Click" CssClass="button" />
        <asp:LinkButton ID="lbtnContinueShopping" runat="server"
            PostBackUrl="~/Order.aspx" CausesValidation="False">Continue Shopping</asp:LinkButton>
    
    
</asp:Content>
