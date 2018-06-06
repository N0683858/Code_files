<%@ Page Title="" Language="C#" MasterPageFile="~/Customers/CustMasterPage.master" AutoEventWireup="true" CodeFile="CustInvoice.aspx.cs" Inherits="Customers_CustomerInvoice" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <h1>Invoice</h1> 
    
        <asp:TextBox ID="txtData" runat="server" TextMode="MultiLine" Columns="50" Rows="20" Width="648px"></asp:TextBox>  
        <br /><br />
        <asp:Button ID="btnContinue" runat="server"
            PostBackUrl="~/Customers/CustOrder.aspx" Text="Continue Shopping" />
        <asp:Button ID="edit_btn" runat="server"
            PostBackUrl="~/Customers/CustCheckOut.aspx" Text="Edit" />
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

