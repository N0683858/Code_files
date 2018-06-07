<%@ Page Title="" Language="C#" MasterPageFile="~/Admin/AdminMasterPage.master" AutoEventWireup="true" CodeFile="AdminChangePass.aspx.cs" Inherits="Admin_AdminChangePass" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="formPlaceHolder" Runat="Server">

    <asp:Label runat="server" ID="msg_lbl" />
    <asp:Label ID="isUsernameValid" runat="server"></asp:Label> 
    <h2>Profile</h2>
    <div id="side-navBar">
        <asp:HyperLink NavigateUrl="~/Admin/MaintenancePage.aspx" class="sideLinks" ID="accDetails" runat="server">Account Details</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/AdminChangePass.aspx" class="sideLinks" ID="changePass" runat="server" ForeColor="#FF0066">Change Password</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/CreateNewUser.aspx" class="sideLinks" ID="newAcc" runat="server">New Account</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/listInvoices.aspx" class="sideLinks" ID="listInvoices" runat="server">View Invoices</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/EditInvoices.aspx" class="sideLinks" ID="editBillingInfo" runat="server">User Billing Info</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/AddNewProducts.aspx" class="sideLinks" ID="HyperLink1" runat="server">Add Products</asp:HyperLink> <br />
    </div>
    <div id="login_pg" class="panel panel-primary">
        <h2>Change Password</h2>

        <!------------------------------------------    Forgot Password Form      ------------------------------------->
        <div class="panel-body">            
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
<asp:Content ID="Content4" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

