<%@ Page Title="" Language="C#" MasterPageFile="~/Admin/AdminMasterPage.master" AutoEventWireup="true" CodeFile="AdminCart.aspx.cs" Inherits="Admin_AdminCartPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <asp:ListBox ID="lstCart" runat="server"></asp:ListBox>
    <div id="cartbuttons">               
        <asp:Button ID="btnRemove" runat="server" CssClass="button" Text="Remove Item" OnClick="btnRemove_Click" Width="255px" />
        <br />
        <asp:Button ID="btnEmpty" runat="server" CssClass="button" Text="Empty Cart" OnClick="btnEmpty_Click" Width="255px" />               
    </div>
    <div id="shopbuttons">              
        <asp:Button ID="btnContinue" runat="server" CssClass="button" PostBackUrl="~/Admin/AdminOrder.aspx" Text="Continue Shopping" Width="296px" />
        <asp:Button ID="btnCheckOut" runat="server" CssClass="button" Text="Check Out" OnClick="btnCheckOut_Click" Width="255px" /><br /><br />              
    </div>
    <asp:Label ID="lblMessage" runat="server" EnableViewState="False"></asp:Label><br />
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

