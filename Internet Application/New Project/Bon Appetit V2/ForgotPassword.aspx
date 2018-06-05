<%@ Page Title="" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="ForgotPassword.aspx.cs" Inherits="ForgotPassword" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
</asp:Content>

<asp:Content ID="Content4" ContentPlaceHolderID="formPlaceHolder" Runat="Server">

    <asp:Label runat="server" ID="msg_lbl" />
    <asp:Label ID="isUsernameValid" runat="server"></asp:Label> 
    <div id="login_pg" class="panel panel-primary">
        <h2>Forgot Password</h2>

        <!------------------------------------------    Forgot Password Form      ------------------------------------->
        <div class="panel-body">
            <label>Username: <asp:RequiredFieldValidator ID="RequiredFieldValidator1" Display="Dynamic" runat="server" ControlToValidate="username_tb" ErrorMessage="Please type a username!"></asp:RequiredFieldValidator>
            &nbsp;<asp:TextBox ID="username_tb" PlaceHolder="Username" runat="server" CssClass="form-control" Width="379px" />
            </label>
            <br />
            <asp:Label runat="server">Security Question: What is your is your birth city?</asp:Label>
            <label>Answer: <asp:TextBox ID="ans_tb" PlaceHolder="Answer" runat="server" CssClass="form-control" Width="379px" /></label>
            <br />
            <label>New Password: <asp:TextBox ID="password_tb" PlaceHolder="New Password" TextMode="Password" runat="server" CssClass="form-control" Width="424px" /></label>
            <br />
            <label>Re-Type Password: <asp:TextBox ID="reTypePass_tb" PlaceHolder="Re-Type Password" TextMode="Password" runat="server" CssClass="form-control" Width="424px" />
            <asp:CompareValidator ID="CompareValidator1" Display="Dynamic" runat="server" ControlToCompare="password_tb" ControlToValidate="reTypePass_tb" ErrorMessage="Password does not match!"></asp:CompareValidator>
            </label>
        </div>

        <!------------------------------------------    Conitnue Button     ------------------------------------->
        <div class="panel-footer">
            <asp:Button runat="server" ID="continue_btn" OnClick="continue_btn_Click" CssClass="btn btn-primary" Text="Continue" />
            <asp:Button runat="server" ID="cancel_btn" CausesValidation="false" OnClick="cancel_btn_Click" CssClass="btn btn-primary" Text="Cancel" />
        </div>
    </div>


</asp:Content>
<asp:Content ID="Content5" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

