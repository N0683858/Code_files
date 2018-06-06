<%@ Page Title="" Language="C#" MasterPageFile="~/Admin/AdminMasterPage.master" AutoEventWireup="true" CodeFile="listInvoices.aspx.cs" Inherits="Admin_Invoices" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
    <!-- 
        <link href="../css/listInvoices.css" rel="stylesheet" type="text/css" /> 
    -->
    <style type="text/css">

        .auto-style2 {
            width: 63px;
        }
        .auto-style3 {
            width: 102px;
        }
        .auto-style4 {
            width: 131px;
        }
        .auto-style5 {
            width: 100px;
            height: 20px;
        }
        </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <h2>Profile</h2>
    <div id="side-navBar">
        <asp:HyperLink NavigateUrl="~/Admin/MaintenancePage.aspx" class="sideLinks" ID="accDetails" runat="server">Account Details</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/AdminChangePass.aspx" class="sideLinks" ID="changePass" runat="server">Change Password</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/CreateNewUser.aspx" class="sideLinks" ID="newAcc" runat="server">New Account</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/listInvoices.aspx" class="sideLinks" ID="listInvoices" runat="server" ForeColor="#FF0066">View Invoices</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/EditInvoices.aspx" class="sideLinks" ID="editBillingInfo" runat="server">User Billing Info</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/AddNewProducts.aspx" class="sideLinks" ID="HyperLink1" runat="server">Add Products</asp:HyperLink> <br />
    </div>
     <asp:Label ID="Label1" runat="server" Text="Choose an invoice:"></asp:Label>
      &nbsp;
          <asp:DropDownList ID="ddlInvoice" runat="server" AutoPostBack="True" DataSourceID="SqlDataSource1" DataTextField="InvoiceNumber" DataValueField="InvoiceNumber"></asp:DropDownList>

        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:Database %>" SelectCommand="SELECT [InvoiceNumber] FROM [Invoices] WHERE [Total] > 300"></asp:SqlDataSource>

        <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:Database %>" SelectCommand="SELECT [ProductID], [UnitPrice], [Quantity], [Extension] FROM [LineItems] WHERE ([InvoiceNumber] = @InvoiceNumber)">
            <SelectParameters>
                <asp:ControlParameter ControlID="ddlInvoice" Name="InvoiceNumber" PropertyName="SelectedValue" Type="Int32"/>
            </SelectParameters>
        </asp:SqlDataSource>
        <br />
        <asp:DataList ID="DataList1" runat="server" DataSourceID="SqlDataSource2" CellPadding="4" ForeColor="#333333" Width="400px">
            <AlternatingItemStyle BackColor="White" />
            <FooterStyle BackColor="#FF0066" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#FF0066" Font-Bold="True" ForeColor="White" />
            <HeaderTemplate>
                <table class="auto-style1">
                    <tr>
                        <td class="auto-style2">Product</td>
                        <td class="auto-style3">Unit Price</td>
                        <td class="auto-style4">Quantity</td>
                        <td>Extension</td>
                    </tr>
                </table>
            </HeaderTemplate>
            <ItemStyle BackColor="#E3EAEB" />
            <ItemTemplate>
<br />
                <table class="auto-style1">
                    <tr>
                        <td class="auto-style5">
                            <asp:Label ID="ProductIDLabel" runat="server" Text='<%# Eval("ProductID") %>'></asp:Label>
                        </td>
                        <td class="auto-style5">
                            <asp:Label ID="UnitPriceLabel" runat="server" Text='<%# Eval("UnitPrice", "{0:C}") %>'></asp:Label>
                        </td>
                        <td class="auto-style5">
                            <asp:Label ID="QuantityLabel" runat="server" Text='<%# Eval("Quantity") %>'></asp:Label>
                        </td>
                        <td class="auto-style5">
                            <asp:Label ID="ExtensionLabel" runat="server" Text='<%# Eval("Extension", "{0:C}") %>'></asp:Label>
                        </td>
                    </tr>
                </table>
                <br />
            </ItemTemplate>
            <SelectedItemStyle BackColor="#C5BBAF" Font-Bold="True" ForeColor="#333333" />
        </asp:DataList>
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

