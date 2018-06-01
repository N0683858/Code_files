<%@ Page Title="" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="CheckOut2.aspx.cs" Inherits="CheckOut2" %>
<%@ MasterType VirtualPath="~/Site.master" %>

<asp:Content ID="headContent" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
    
</asp:Content>


<asp:Content ID="formContent" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <h1>Invoice</h1> 
    
        <asp:TextBox ID="txtData" runat="server" TextMode="MultiLine" Columns="50" Rows="20"></asp:TextBox>  
        <br /><br />
        <asp:Button ID="btnContinue" runat="server"
            PostBackUrl="~/Order.aspx" Text="Continue Shopping" />
</asp:Content>
