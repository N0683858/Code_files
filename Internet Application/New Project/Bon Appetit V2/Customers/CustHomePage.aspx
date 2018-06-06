<%@ Page Title="" Language="C#" MasterPageFile="~/Customers/CustMasterPage.master" AutoEventWireup="true" CodeFile="CustHomePage.aspx.cs" Inherits="Customers_CustomerHomePage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headPlaceHolder" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="headerPlaceHolder" Runat="Server">
     <!-- Header Section -->
        <header id="header" class="alt">
		    <div class="inner">
			    <h1>Bon Appétit</h1>
			    <p>The worlds best restaurant website </p>
		    </div>
	    </header>
</asp:Content>

<asp:Content ID="Content4" ContentPlaceHolderID="formPlaceHolder" Runat="Server">
    <!-- Banner -->
    <section id="intro" class="main">
        <span class="icon fa-diamond major"></span>
        <h2>Best in the World!</h2>
        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed vitae<br />
        malesuada turpis. Nam pellentesque in ac aliquam. Aliquam tempor<br />
        mi porta egestas maximus lorem ipsum dolor.</p>
        <ul class="actions">
        <li><a href="#" class="button big">Learn More</a></li>
        </ul>
    </section>
    <br />
    <!-- Banner End -->
    <section class="main items">
	    <article class="item">
		    <header>
			    <a href="../Customers/CustMenu.aspx"><img src="../images/burg.jpg" width="100%"; alt="" /></a>
				<h3>Hawaiian Burgers</h3>
		    </header>
		    <p>Fusce malesuada efficitur venenatis. Pellentesque tempor leo sed massa hendrerit hendrerit. In sed feugiat est, eu congue elit. Ut porta magna vel felis sodales vulputate. Donec faucibus dapibus lacus non ornare.</p>
		    <ul class="actions">
			    <li><a href="../Customers/CustMenu.aspx" class="button">More</a></li>
		    </ul>
	    </article>
	    <article class="item">
		    <header>
			    <a href="../Customers/CustMenu.aspx"><img src="../images//pink.jpeg" width="100%" alt="" /></a>
			    <h3>Ice Cold Drinks</h3>
		    </header>
		    <p>Fusce malesuada efficitur venenatis. Pellentesque tempor leo sed massa hendrerit hendrerit. In sed feugiat est, eu congue elit. Ut porta magna vel felis sodales vulputate. Donec faucibus dapibus lacus non ornare.</p>
		    <ul class="actions">
			    <li><a href="../Customers/CustMenu.aspx" class="button">More</a></li>
		    </ul>
	    </article>
	    <article class="item">
		    <header>
			    <a href="../Customers/CustMenu.aspx"><img src="../images/cherryD.jpeg" width="100%" alt="" /></a>
			    <h3>Delicious Desserts</h3>
		    </header>
		    <p>Fusce malesuada efficitur venenatis. Pellentesque tempor leo sed massa hendrerit hendrerit. In sed feugiat est, eu congue elit. Ut porta magna vel felis sodales vulputate. Donec faucibus dapibus lacus non ornare.</p>
		    <ul class="actions">
			    <li><a href="../Customers/CustMenu.aspx" class="button">More</a></li>
		    </ul>
	    </article>
	    <article class="item">
		    <header>
			    <a href="../Customers/CustMenu.aspx"><img src="../images/veg4.jpeg" width="100%" alt="" /></a>
			    <h3>Vegeterian</h3>
		    </header>
		    <p>Fusce malesuada efficitur venenatis. Pellentesque tempor leo sed massa hendrerit hendrerit. In sed feugiat est, eu congue elit. Ut porta magna vel felis sodales vulputate. Donec faucibus dapibus lacus non ornare.</p>
		    <ul class="actions">
			    <li><a href="../Customers/CustMenu.aspx" class="button">More</a></li>
		    </ul>
	    </article>
    </section>

    <!-- CTA -->
    <section id="cta" class="main special">
	    <h2>Etiam veroeros lorem</h2>
	    <p>Phasellus ac augue ac magna auctor tempus proin<br />
	    accumsan lacus a nibh commodo in pellentesque dui<br />
	    in hac habitasse platea dictumst.</p>
	    <ul class="actions">
		    <li><a href="#" class="button big">Get Started</a></li>
	    </ul>
    </section>
</asp:Content>
<asp:Content ID="Content5" ContentPlaceHolderID="footerPlaceHolder" Runat="Server">
</asp:Content>

