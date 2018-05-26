<%@ Page Title="" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="RegisterationPage.aspx.cs" Inherits="LoginPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <div id="registeration_pg" class="panel panel-primary">
        <div class="panel-heading">User Registeration</div>

        <!------------------------------------------    Registeration Form      ------------------------------------->
        <div class="panel-body">
            <label>Username: <asp:TextBox ID="username_tb" runat="server" CssClass="form-control" /></label>
            <br />
            <label>First Name: <asp:TextBox ID="firstname_tb" runat="server" CssClass="form-control" /></label>
            <br />
            <label>Last Name: <asp:TextBox ID="lastname_tb" runat="server" CssClass="form-control" /></label>
            <br />
            <label>Password: <asp:TextBox ID="password_tb" runat="server" CssClass="form-control" /></label>
        </div>

        <!------------------------------------------    Registeration Button     ------------------------------------->
        <div class="panel-footer">
            <asp:Button runat="server" ID="register_btn" OnClick="register_btn_Click" CssClass="btn btn-primary" Text="Register" />
        </div>

    </div>
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

