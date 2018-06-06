<%@ Page Title="" Language="C#" MasterPageFile="~/Admin/AdminMasterPage.master" AutoEventWireup="true" CodeFile="MaintenancePage.aspx.cs" Inherits="Admin_MaintenancePage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
</asp:Content>

<asp:Content ID="Content4" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <h2>Profile</h2>
    <div id="side-navBar">
        <asp:HyperLink NavigateUrl="~/Admin/MaintenancePage.aspx" class="sideLinks" ID="accDetails" runat="server">Account Details</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/AdminChangePass.aspx" class="sideLinks" ID="changePass" runat="server">Change Password</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/CreateNewUser.aspx" class="sideLinks" ID="newAcc" runat="server">New Account</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/listInvoices.aspx" class="sideLinks" ID="listInvoices" runat="server">View Invoices</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/EditUsers.aspx" class="sideLinks" ID="editBillingInfo" runat="server">User Billing Info</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/AddNewProducts.aspx" class="sideLinks" ID="HyperLink1" runat="server">Add Products</asp:HyperLink> <br />
    </div>

    <div id="accountDetails">
        <asp:Label ID="username_lbl" CssClass="profile_lbls" runat="server" Text="Username: "></asp:Label><asp:Label ID="username_lbl2" runat="server"></asp:Label> <br />
        <asp:Label ID="pass_lbl" CssClass="profile_lbls" runat="server" Text="Password: "></asp:Label><asp:Label ID="pass_lbl2" runat="server"></asp:Label><br />
        <asp:Label ID="role_lbl" CssClass="profile_lbls" runat="server" Text="Role: "></asp:Label><asp:Label ID="role_lbl2" runat="server"></asp:Label>
    </div>
</asp:Content>
<asp:Content ID="Content5" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

