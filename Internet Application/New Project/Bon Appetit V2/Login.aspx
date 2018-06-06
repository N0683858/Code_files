<%@ Page Title="" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="Login.aspx.cs" Inherits="Login" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
</asp:Content>

<asp:Content ID="Content4" ContentPlaceHolderID="formPlaceHolder" Runat="Server">

    <asp:Label runat="server" ID="msg_lbl" />
    <asp:Label ID="isUsernameValid" runat="server"></asp:Label> 
    <div id="login_pg" class="panel panel-primary">
        <h2>Login</h2>

        <!------------------------------------------    Login Form      ------------------------------------->
        <div class="panel-body">
            <label>Username:<asp:RequiredFieldValidator ID="RequiredFieldValidator1" Display="Dynamic" runat="server" ControlToValidate="username_tb" ErrorMessage="Please type a username!"></asp:RequiredFieldValidator>
            &nbsp;<asp:TextBox ID="username_tb" PlaceHolder="Username" runat="server" CssClass="form-control" Width="379px" />
            </label>
            <br />
            <label>Password: <asp:TextBox ID="password_tb" PlaceHolder="Password" TextMode="Password" runat="server" CssClass="form-control" Width="379px" /></label>
        </div>

        <!------------------------------------------    Login Button     ------------------------------------->
        <div class="panel-footer">
            <asp:Button runat="server" ID="Login_btn" OnClick="Login_btn_Click" CssClass="btn btn-primary" Text="Login" Width="136px" />
            <asp:Button runat="server" ID="cancel_btn" CausesValidation="false" OnClick="cancel_btn_Click" CssClass="btn btn-primary" Text="Cancel" Width="148px" />
            <asp:Button runat="server" ID="forgotPass_btn" CausesValidation="false" OnClick="forgotPass_btn_Click" CssClass="btn btn-primary" Text="Forgot Password" Width="270px" />
        </div>
    </div>

</asp:Content>
<asp:Content ID="Content5" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

