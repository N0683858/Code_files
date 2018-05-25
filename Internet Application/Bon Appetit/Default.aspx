<%@ Page Title="" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <asp:LoginView ID="LoginView1" runat="server">
        <AnonymousTemplate>
            Hello, Please <asp:LoginStatus ID="LoginStatus1" runat="server" />.
        </AnonymousTemplate>
        <LoggedInTemplate>
            Hello <asp:LoginName ID="LoginName1" runat="server" /> welcome back.
            <asp:LoginStatus ID="LoginStatus2" runat="server" />
        </LoggedInTemplate>
    </asp:LoginView>
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

