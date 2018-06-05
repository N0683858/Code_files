<%@ Page Title="" Language="C#" MasterPageFile="~/Customers/CustMasterPage.master" AutoEventWireup="true" CodeFile="UserProfile.aspx.cs" Inherits="Customers_UserProfile" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <div id="side-navBar">
        <asp:HyperLink class="sideLinks" ID="accDetails" runat="server">Account Details</asp:HyperLink> <br />
        <asp:HyperLink class="sideLinks" ID="changePass" runat="server">Change Password</asp:HyperLink> <br />
        <!-- <asp:Button ID="Button1" runat="server" Text="Account Details" Width="296px" /><br />
        <asp:Button ID="Button2" runat="server" Text="Change Password" /> -->
    </div>

    <div id="accountDetails">
        <asp:Label ID="username" runat="server" Text="Username: "></asp:Label>
    </div>
</asp:Content>
<asp:Content ID="Content5" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

