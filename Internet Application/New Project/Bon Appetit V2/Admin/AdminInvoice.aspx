<%@ Page Title="" Language="C#" MasterPageFile="~/Admin/AdminMasterPage.master" AutoEventWireup="true" CodeFile="AdminInvoice.aspx.cs" Inherits="Admin_AdminInvoice" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="formPlaceHolder" Runat="Server">

        <h1>Invoice</h1> 
    
        <asp:TextBox ID="txtData" runat="server" TextMode="MultiLine" Columns="50" Rows="20" Width="564px"></asp:TextBox>  
        <br /><br />
        <asp:Button ID="btnContinue" runat="server"
            PostBackUrl="~/Admin/AdminOrder.aspx" Text="Continue Shopping" />
        <asp:Button ID="edit_btn" runat="server"
            PostBackUrl="~/Admin/AdminCheckOut.aspx" Text="Edit" />

</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

