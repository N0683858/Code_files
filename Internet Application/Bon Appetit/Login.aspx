<%@ Page Title="" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="Login.aspx.cs" Inherits="Login" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
    <link rel="stylesheet" href="css/Login.css" />
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <asp:Login ID="Login1" runat="server" Width="411px"  CreateUserText="Register" CreateUserUrl="~/Register.aspx" DestinationPageUrl="~/Default.aspx" Font-Names="Verdana" Font-Size="0.8em" TextLayout="TextOnTop" BorderPadding="5">
        <InstructionTextStyle Font-Italic="True" ForeColor="Black" Font-Size="2em"/>
        <LoginButtonStyle BackColor="White" BorderColor="#CC9966" BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" Font-Size="1em" ForeColor="#990000" />
        <TextBoxStyle Font-Size="2em" />
        <TitleTextStyle BackColor="#333333" Font-Bold="True" Font-Size="2em" ForeColor="White" />
    </asp:Login>
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
    
</asp:Content>

