<%@ Page Title="" Language="C#" MasterPageFile="~/Customers/CustMasterPage.master" AutoEventWireup="true" CodeFile="CustCart.aspx.cs" Inherits="Customers_CustomerCart" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
    <link href="../css/Cart.css" rel="stylesheet" />
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="formPlaceHolder" Runat="Server">

    <asp:ListBox ID="lstCart" runat="server"></asp:ListBox>
    <div id="cartbuttons">               
        <asp:Button ID="btnRemove" runat="server" CssClass="button" Text="Remove Item" OnClick="btnRemove_Click" Width="255px" />
        <br />
        <asp:Button ID="btnEmpty" runat="server" CssClass="button" Text="Empty Cart" OnClick="btnEmpty_Click" Width="255px" />               
    </div>
    <div id="shopbuttons">              
        <asp:Button ID="btnContinue" runat="server" CssClass="button" PostBackUrl="~/Customers/CustOrder.aspx" Text="Continue Shopping" Width="296px" />
        <asp:Button ID="btnCheckOut" runat="server" CssClass="button" Text="Check Out" OnClick="btnCheckOut_Click" Width="255px" /><br /><br />              
    </div>
    <asp:Label ID="lblMessage" runat="server" EnableViewState="False"></asp:Label><br />

</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

