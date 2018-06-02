<%@ Page Title="" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="Login.aspx.cs" Inherits="Login" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="navBar" Runat="Server">
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="formPlaceHolder" Runat="Server">

    <asp:Label runat="server" ID="msg_lbl" /> 
    <div id="login_pg" class="panel panel-primary">
        <div class="panel-heading">Login</div>

        <!------------------------------------------    Registeration Form      ------------------------------------->
        <div class="panel-body">
            <label>Username:<asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="username_tb" ErrorMessage="Please type a username!"></asp:RequiredFieldValidator>
            &nbsp;<asp:TextBox ID="username_tb" runat="server" CssClass="form-control" Width="379px" />
            </label>
            <br />
            <label>Password: <asp:TextBox ID="password_tb" TextMode="Password" runat="server" CssClass="form-control" Width="379px" /></label>
        </div>

        <!------------------------------------------    Registeration Button     ------------------------------------->
        <div class="panel-footer">
            <asp:Button runat="server" ID="Login_btn" CssClass="btn btn-primary" Text="Login" />
            <asp:Label ID="isUsernameValid" runat="server"></asp:Label>
        </div>
    </div>

</asp:Content>
<asp:Content ID="Content5" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

