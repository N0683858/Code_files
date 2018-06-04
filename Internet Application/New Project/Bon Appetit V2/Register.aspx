<%@ Page Title="" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="Register.aspx.cs" Inherits="Register" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="navBar" Runat="Server">
</asp:Content>


<asp:Content ID="Content4" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
     <!-- when your register it will display a message -->
    <asp:Label runat="server" ID="msg_lbl" />
    <asp:Label ID="isUsernameValid" runat="server"></asp:Label> 
    <div id="registeration_pg" class="panel panel-primary">
        <h2>User Registeration</h2>

        <!------------------------------------------    Registeration Form      ------------------------------------->
        <div class="panel-body">
            <label>Username:<asp:RequiredFieldValidator ID="RequiredFieldValidator1" Display="Dynamic" runat="server" ControlToValidate="username_tb" ErrorMessage="Please type a username!"></asp:RequiredFieldValidator>
            &nbsp;<asp:TextBox ID="username_tb" runat="server" CssClass="form-control" Width="424px" />
            </label>
            <br />
            <label>Password: <asp:TextBox ID="password_tb" TextMode="Password" runat="server" CssClass="form-control" Width="424px" /></label>
            <br />
            <label>Re-Type Password: <asp:TextBox ID="reTypePass_tb" TextMode="Password" runat="server" CssClass="form-control" Width="424px" />
            <asp:CompareValidator ID="CompareValidator1" Display="Dynamic" runat="server" ControlToCompare="password_tb" ControlToValidate="reTypePass_tb" ErrorMessage="Password does not match!"></asp:CompareValidator>
            </label>
            <br />
            <asp:Label runat="server">Security Question: What is your is your birth city?</asp:Label>
            <label>Answer: <asp:TextBox ID="security_tb" runat="server" CssClass="form-control" Width="424px" /></label>
        </div>

        <!------------------------------------------    Registeration Button     ------------------------------------->
        <div class="panel-footer">
            <asp:Button runat="server" ID="register_btn" OnClick="register_btn_Click" CssClass="btn btn-primary" Text="Register" />
            
        </div>

    </div>
</asp:Content>
<asp:Content ID="Content5" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

