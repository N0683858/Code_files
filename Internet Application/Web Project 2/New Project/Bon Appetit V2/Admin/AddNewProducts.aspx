<%@ Page Title="" Language="C#" MasterPageFile="~/Admin/AdminMasterPage.master" AutoEventWireup="true" CodeFile="AddNewProducts.aspx.cs" Inherits="Admin_AddNewProducts" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <h2>Profile</h2>
    <div id="side-navBar">
        <asp:HyperLink NavigateUrl="~/Admin/MaintenancePage.aspx" class="sideLinks" ID="accDetails" runat="server">Account Details</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/AdminChangePass.aspx" class="sideLinks" ID="changePass" runat="server">Change Password</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/CreateNewUser.aspx" class="sideLinks" ID="newAcc" runat="server">New Account</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/listInvoices.aspx" class="sideLinks" ID="listInvoices" runat="server">View Invoices</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/EditInvoices.aspx" class="sideLinks" ID="editBillingInfo" runat="server">User Billing Info</asp:HyperLink> <br />
        <asp:HyperLink NavigateUrl="~/Admin/AddNewProducts.aspx" class="sideLinks" ID="HyperLink1" runat="server" ForeColor="#FF0066">Add Products</asp:HyperLink> <br />
    </div>

    <div id="registeration_pg" class="panel panel-primary">
        <h2>Add New Product</h2>

        <!------------------------------------------    Registeration Form      ------------------------------------->
        <div class="panel-body">
            <label>Product ID:<asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ErrorMessage="Product ID Required!" Display="Dynamic" ControlToValidate="productID_tb"></asp:RequiredFieldValidator>
            &nbsp;<asp:TextBox ID="productID_tb" PlaceHolder="Product ID" runat="server" CssClass="form-control" Width="424px" ControlToValidate="productID_tb" />
            </label>
            <br />
            <label>Name:<asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ErrorMessage="Name Is Required!" Display="Dynamic" ControlToValidate="name_tb"></asp:RequiredFieldValidator>
                <asp:TextBox ID="name_tb" PlaceHolder="Name" runat="server" CssClass="form-control" Width="424px" /></label>
            <br />
            <label>Short Description:<asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" ErrorMessage="Short Description Required!" Display="Dynamic" ControlToValidate="shortDes_tb"></asp:RequiredFieldValidator>
                <asp:TextBox ID="shortDes_tb" PlaceHolder="Short Description" runat="server" CssClass="form-control" Width="424px" />            
            </label>
            <br />
            <label>Long Description:<asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server" ErrorMessage="Long Description Required!" Display="Dynamic" ControlToValidate="longDes_tb"></asp:RequiredFieldValidator>
                <asp:TextBox ID="longDes_tb" PlaceHolder="Long Description" TextMode="MultiLine" Rows="5" runat="server" CssClass="form-control" Width="424px" />            
            </label>
            <br /> <!-- change cat id text box to drop down -->
            <label>Catagory ID:<asp:RequiredFieldValidator ID="RequiredFieldValidator5" runat="server" ErrorMessage="Catagory ID Required!" Display="Dynamic" ControlToValidate="catID_ddl"></asp:RequiredFieldValidator> 
               <asp:DropDownList ID="catID_ddl" runat="server">
                   <asp:ListItem Value="burg">Burgers</asp:ListItem>
                   <asp:ListItem Value="desserts">Desserts</asp:ListItem>
                   <asp:ListItem Value="drink">Drinks</asp:ListItem>
                   <asp:ListItem>Vegetarian</asp:ListItem>
               </asp:DropDownList>
                <!-- <asp:TextBox ID="catID_tb" PlaceHolder="Catagory ID" runat="server" CssClass="form-control" Width="424px" /> -->           
            </label>
            <br />
            <label>Unit Price:<asp:RequiredFieldValidator ID="RequiredFieldValidator6" runat="server" ErrorMessage="Unit Price Is Required!" Display="Dynamic" ControlToValidate="unitPrice_tb"></asp:RequiredFieldValidator>
                
                 <asp:TextBox ID="unitPrice_tb" PlaceHolder="Unit Price" runat="server" CssClass="form-control" Width="424px" />            
            </label>
            <br />
            <label>In Stock:<asp:RequiredFieldValidator ID="RequiredFieldValidator7" runat="server" ErrorMessage="On Hand Price Required!" Display="Dynamic" ControlToValidate="onHand_tb"></asp:RequiredFieldValidator>
                <asp:TextBox ID="onHand_tb" PlaceHolder="In Stock" runat="server" CssClass="form-control" Width="424px" />            
            </label>
            <br />
            <label>Image: 
                 <asp:FileUpload ID="imgFile" runat="server" />           
            </label>
        </div>

        <!------------------------------------------    Registeration Button     ------------------------------------->
        <div class="panel-footer">
            <asp:Button runat="server" ID="add_btn" OnClick="add_btn_Click" CssClass="btn btn-primary" Text="Add" />
            <asp:Button runat="server" ID="cancel_btn" CausesValidation="false" OnClick="cancel_btn_Click" CssClass="btn btn-primary" Text="Cancel" />
            
        </div>

    </div>
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

