<%@ Page Title="" Language="C#" MasterPageFile="~/Admin/AdminMasterPage.master" AutoEventWireup="true" CodeFile="EditUsers.aspx.cs" Inherits="Admin_EditUsers" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>


<asp:Content ID="Content2" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
     <div id="gridview">
            <asp:DetailsView ID="DetailsView1" runat="server" AutoGenerateRows="False" DataKeyNames="Email" DataSourceID="SqlDataSource2" Height="114px" Width="479px" OnItemDeleted="DetailsView1_ItemDeleted" OnItemInserted="DetailsView1_ItemInserted" OnItemUpdated="DetailsView1_ItemUpdated">
                <Fields>
                    <asp:TemplateField HeaderText="Email" SortExpression="Email">
                        <EditItemTemplate>
                            <asp:Label ID="Email_Lbl" runat="server" Text='<%# Eval("Email") %>'></asp:Label>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator11" runat="server" ControlToValidate="Email_Lbl" ErrorMessage="Email Required!"></asp:RequiredFieldValidator>
                        </EditItemTemplate>
                        <InsertItemTemplate>
                            <asp:TextBox ID="Email_tb" runat="server" Text='<%# Bind("Email") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator12" runat="server" ControlToValidate="Email_tb" ErrorMessage="Email Required!"></asp:RequiredFieldValidator>
                        </InsertItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="Label1" runat="server" Text='<%# Bind("Email") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="LastName" SortExpression="LastName">
                        <EditItemTemplate>
                            <asp:TextBox ID="LastName_tb" runat="server" MaxLength="20" Text='<%# Bind("LastName") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator13" runat="server" ControlToValidate="LastName_tb" ErrorMessage="Last Name Required!"></asp:RequiredFieldValidator>
                        </EditItemTemplate>
                        <InsertItemTemplate>
                            <asp:TextBox ID="TextBox2" runat="server" Text='<%# Bind("LastName") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator14" runat="server" ControlToValidate="TextBox2" ErrorMessage="Last Name Required!"></asp:RequiredFieldValidator>
                        </InsertItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="Label2" runat="server" Text='<%# Bind("LastName") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="FirstName" SortExpression="FirstName">
                        <EditItemTemplate>
                            <asp:TextBox ID="FirstName_tb" runat="server" MaxLength="20" Text='<%# Bind("FirstName") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator15" runat="server" ControlToValidate="FirstName_tb" ErrorMessage="First Name Required!"></asp:RequiredFieldValidator>
                        </EditItemTemplate>
                        <InsertItemTemplate>
                            <asp:TextBox ID="TextBox3" runat="server" Text='<%# Bind("FirstName") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator16" runat="server" ControlToValidate="TextBox3" ErrorMessage="First Name Required!"></asp:RequiredFieldValidator>
                        </InsertItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="Label3" runat="server" Text='<%# Bind("FirstName") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="Address" SortExpression="Address">
                        <EditItemTemplate>
                            <asp:TextBox ID="Address_tb" runat="server" MaxLength="40" Text='<%# Bind("Address") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator17" runat="server" ControlToValidate="Address_tb" ErrorMessage="Address Required!"></asp:RequiredFieldValidator>
                        </EditItemTemplate>
                        <InsertItemTemplate>
                            <asp:TextBox ID="TextBox4" runat="server" Text='<%# Bind("Address") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator18" runat="server" ControlToValidate="TextBox4" ErrorMessage="Address Required!"></asp:RequiredFieldValidator>
                        </InsertItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="Label4" runat="server" Text='<%# Bind("Address") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="City" SortExpression="City">
                        <EditItemTemplate>
                            <asp:TextBox ID="City_tb" runat="server" MaxLength="30" Text='<%# Bind("City") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator19" runat="server" ControlToValidate="City_tb" ErrorMessage="City Required!"></asp:RequiredFieldValidator>
                        </EditItemTemplate>
                        <InsertItemTemplate>
                            <asp:TextBox ID="TextBox5" runat="server" Text='<%# Bind("City") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator20" runat="server" ControlToValidate="TextBox5" ErrorMessage="City Required!"></asp:RequiredFieldValidator>
                        </InsertItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="Label5" runat="server" Text='<%# Bind("City") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="State" SortExpression="State">
                        <EditItemTemplate>
                            <asp:DropDownList ID="StateList1" runat="server" DataSourceID="SqlDataSource3" DataTextField="StateName" DataValueField="StateCode" Text='<%# Bind("State") %>' SelectedValue='<%# Bind("State") %>'>
                            </asp:DropDownList>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator9" runat="server" ErrorMessage="State is required!" ControlToValidate="StateList1">*</asp:RequiredFieldValidator>
                        </EditItemTemplate>
                        <InsertItemTemplate>
                            <asp:DropDownList ID="StateList2" runat="server" DataSourceID="SqlDataSource3" DataTextField="StateName" DataValueField="StateCode" Text='<%# Bind("State") %>' SelectedValue='<%# Bind("State") %>'>
                            </asp:DropDownList>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator10" runat="server" ErrorMessage="State is required!" ControlToValidate="StateList2">*</asp:RequiredFieldValidator>
                        </InsertItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="Label6" runat="server" Text='<%# Bind("State") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="ZipCode" SortExpression="ZipCode">
                        <EditItemTemplate>
                            <asp:TextBox ID="ZipCode_tb" runat="server" MaxLength="9" Text='<%# Bind("ZipCode") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator21" runat="server" ControlToValidate="ZipCode_tb" ErrorMessage="State Required!"></asp:RequiredFieldValidator>
                        </EditItemTemplate>
                        <InsertItemTemplate>
                            <asp:TextBox ID="TextBox7" runat="server" Text='<%# Bind("ZipCode") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator22" runat="server" ControlToValidate="TextBox7" ErrorMessage="State Required!"></asp:RequiredFieldValidator>
                        </InsertItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="Label7" runat="server" Text='<%# Bind("ZipCode") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="PhoneNumber" SortExpression="PhoneNumber">
                        <EditItemTemplate>
                            <asp:TextBox ID="PhoneNumber_tb" runat="server" MaxLength="20" Text='<%# Bind("PhoneNumber") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator23" runat="server" ControlToValidate="PhoneNumber_tb" ErrorMessage="Phone Number Required!"></asp:RequiredFieldValidator>
                        </EditItemTemplate>
                        <InsertItemTemplate>
                            <asp:TextBox ID="TextBox8" runat="server" Text='<%# Bind("PhoneNumber") %>'></asp:TextBox>
                            <asp:RequiredFieldValidator ID="RequiredFieldValidator24" runat="server" ControlToValidate="TextBox8" ErrorMessage="Phone Number Required!"></asp:RequiredFieldValidator>
                        </InsertItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="Label8" runat="server" Text='<%# Bind("PhoneNumber") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:CommandField ButtonType="Button" ShowDeleteButton="True" ShowEditButton="True" ShowInsertButton="True" />
                </Fields>
            </asp:DetailsView>
            <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConflictDetection="CompareAllValues" ConnectionString="<%$ ConnectionStrings:Database %>" DeleteCommand="DELETE FROM [Customers] WHERE [Email] = @original_Email AND [LastName] = @original_LastName AND [FirstName] = @original_FirstName AND [Address] = @original_Address AND [City] = @original_City AND [State] = @original_State AND [ZipCode] = @original_ZipCode AND [PhoneNumber] = @original_PhoneNumber" InsertCommand="INSERT INTO [Customers] ([Email], [LastName], [FirstName], [Address], [City], [State], [ZipCode], [PhoneNumber]) VALUES (@Email, @LastName, @FirstName, @Address, @City, @State, @ZipCode, @PhoneNumber)" OldValuesParameterFormatString="original_{0}" SelectCommand="SELECT * FROM [Customers] WHERE ([Email] = @Email)" UpdateCommand="UPDATE [Customers] SET [LastName] = @LastName, [FirstName] = @FirstName, [Address] = @Address, [City] = @City, [State] = @State, [ZipCode] = @ZipCode, [PhoneNumber] = @PhoneNumber WHERE [Email] = @original_Email AND [LastName] = @original_LastName AND [FirstName] = @original_FirstName AND [Address] = @original_Address AND [City] = @original_City AND [State] = @original_State AND [ZipCode] = @original_ZipCode AND [PhoneNumber] = @original_PhoneNumber">
                <DeleteParameters>
                    <asp:Parameter Name="original_Email" Type="String" />
                    <asp:Parameter Name="original_LastName" Type="String" />
                    <asp:Parameter Name="original_FirstName" Type="String" />
                    <asp:Parameter Name="original_Address" Type="String" />
                    <asp:Parameter Name="original_City" Type="String" />
                    <asp:Parameter Name="original_State" Type="String" />
                    <asp:Parameter Name="original_ZipCode" Type="String" />
                    <asp:Parameter Name="original_PhoneNumber" Type="String" />
                </DeleteParameters>
                <InsertParameters>
                    <asp:Parameter Name="Email" Type="String" />
                    <asp:Parameter Name="LastName" Type="String" />
                    <asp:Parameter Name="FirstName" Type="String" />
                    <asp:Parameter Name="Address" Type="String" />
                    <asp:Parameter Name="City" Type="String" />
                    <asp:Parameter Name="State" Type="String" />
                    <asp:Parameter Name="ZipCode" Type="String" />
                    <asp:Parameter Name="PhoneNumber" Type="String" />
                </InsertParameters>
                <SelectParameters>
                    <asp:ControlParameter ControlID="GridView1" Name="Email" PropertyName="SelectedValue" Type="String" />
                </SelectParameters>
                <UpdateParameters>
                    <asp:Parameter Name="LastName" Type="String" />
                    <asp:Parameter Name="FirstName" Type="String" />
                    <asp:Parameter Name="Address" Type="String" />
                    <asp:Parameter Name="City" Type="String" />
                    <asp:Parameter Name="State" Type="String" />
                    <asp:Parameter Name="ZipCode" Type="String" />
                    <asp:Parameter Name="PhoneNumber" Type="String" />
                    <asp:Parameter Name="original_Email" Type="String" />
                    <asp:Parameter Name="original_LastName" Type="String" />
                    <asp:Parameter Name="original_FirstName" Type="String" />
                    <asp:Parameter Name="original_Address" Type="String" />
                    <asp:Parameter Name="original_City" Type="String" />
                    <asp:Parameter Name="original_State" Type="String" />
                    <asp:Parameter Name="original_ZipCode" Type="String" />
                    <asp:Parameter Name="original_PhoneNumber" Type="String" />
                </UpdateParameters>
            </asp:SqlDataSource>
            <asp:SqlDataSource ID="SqlDataSource1" runat="server"
                ConnectionString="<%$ ConnectionStrings:Database %>"
                SelectCommand="SELECT [Email], [LastName], [FirstName] 
                               FROM [Customers] ORDER BY [LastName]">
            </asp:SqlDataSource>
            <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString="<%$ ConnectionStrings:Database %>" SelectCommand="SELECT * FROM [States] ORDER BY [StateName]"></asp:SqlDataSource>
        </div>
        <div id="detailsview">
            <asp:GridView ID="GridView1" runat="server" AllowPaging="True"
                DataKeyNames="Email" DataSourceID="SqlDataSource1"
                AutoGenerateColumns="False" CellPadding="4" GridLines="None" 
                ForeColor="Black" Width="480px" Height="1056px" >
                <Columns>
                    <asp:BoundField DataField="Email" HeaderText="Email"
                        ReadOnly="True" Visible="False">
                    </asp:BoundField>
                    <asp:BoundField DataField="LastName" HeaderText="LastName">
                        <HeaderStyle HorizontalAlign="Left" />
                        <ItemStyle Width="150px" />
                    </asp:BoundField>
                    <asp:BoundField DataField="FirstName" HeaderText="FirstName">
                        <HeaderStyle HorizontalAlign="Left" />
                        <ItemStyle Width="120px" />
                    </asp:BoundField>
                    <asp:CommandField ButtonType="Button" ShowSelectButton="True" />
                </Columns>
                <HeaderStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
                <RowStyle BackColor="White" ForeColor="Black" />
                <AlternatingRowStyle BackColor="#E3EAEB" ForeColor="Black" />
                <SelectedRowStyle BackColor="#F46D11" ForeColor="White" />
                <PagerSettings Mode="NextPreviousFirstLast" />
                <PagerStyle BackColor="#1C5E55" ForeColor="White"
                    HorizontalAlign="Center" />
            </asp:GridView>
            <asp:ValidationSummary ID="ValidationSummary1" runat="server" 
                HeaderText="Please correct the following errors:" CssClass="error" Height="485px" />
            <p>
                <asp:Label ID = "lblError" runat="server" EnableViewState="False" CssClass="error">
                </asp:Label>
            </p>
        </div>
</asp:Content>


<asp:Content ID="Content3" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

