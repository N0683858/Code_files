<%@ Page Title="" Language="C#" MasterPageFile="~/Customers/CustMasterPage.master" AutoEventWireup="true" CodeFile="CustOrder.aspx.cs" Inherits="Customers_CustOrder" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
    <link href="../css/Order.css" rel="stylesheet" />
</asp:Content>

<asp:Content ID="Content3" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <section id="intro" class="main">
    <label>Please select a product&nbsp;</label>
    <asp:DropDownList ID="ddlProducts" runat="server" AutoPostBack="True" DataSourceID="SqlDataSource" DataTextField="Name" DataValueField="ProductID">
    </asp:DropDownList>
    <asp:SqlDataSource ID="SqlDataSource" runat="server" ConnectionString='<%$ ConnectionStrings:Database %>' SelectCommand="SELECT [ProductID], [Name], [ShortDescription], [LongDescription], [ImageFile], [UnitPrice] FROM [Products] ORDER BY [Name]"></asp:SqlDataSource>
    <div id="productData">   
        <asp:Label ID="lblName" runat="server" Text="Label"></asp:Label>
        <asp:Label ID="lblShortDescription" runat="server" Text="Label"></asp:Label>
        <asp:Label ID="lblLongDescription" runat="server" Text="Label"></asp:Label>
        <asp:Label ID="lblUnitPrice" runat="server" Text="Label"></asp:Label>
        <label id="lblQuantity">Quantity&nbsp;</label>
        <asp:TextBox ID="txtQuantity" runat="server" Width="101px"></asp:TextBox>   
        <asp:RequiredFieldValidator ID="rfvQuantity" runat="server" ErrorMessage="Quantity is required." ControlToValidate="txtQuantity" CssClass="validator" Display="Dynamic"></asp:RequiredFieldValidator>       
        <asp:RangeValidator ID="rgvQuantity" runat="server" ErrorMessage="Must be between 1 and 500." ControlToValidate="txtQuantity" CssClass="validator" Display="Dynamic" MaximumValue="500" MinimumValue="1" Type="Integer"></asp:RangeValidator>
        <br />
        <asp:Button ID="btnAdd" runat="server" OnClick="btnAdd_Click" Text="Add to Cart" CssClass="button" />
        <asp:Button ID="btnCart" runat="server" CausesValidation="False" PostBackUrl="~/Customers/CustCart.aspx" Text="Go to Cart" CssClass="button" />
    </div>
    <asp:Image ID="imgProduct" runat="server" /> 
    </section>
</asp:Content>

<asp:Content ID="Content4" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

