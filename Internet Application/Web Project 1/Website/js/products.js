function loadXMLDoc() {
  var xmlhttp = new XMLHttpRequest();
  xmlhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      myFunction(this);
    }
  };

  xmlhttp.open("GET", "../html/XML/products.xml", true);
  xmlhttp.send();
}
function myFunction(xml) {
  var i;
  var xmlDoc = xml.responseXML;
  var table="<tr id='tableHeader'><th>Image</th><th>Name</th><th>Type</th><th>Price</th><th>Order</th></tr>";
  var x = xmlDoc.getElementsByTagName("PRODUCT");
  for (i = 0; i <x.length; i++) {
    table += "<tr><td>" + "<img style='width:60%;' src='" +
    x[i].getElementsByTagName("imageurl")[0].childNodes[0].nodeValue + "'/>" +
    "</td><td>" +
    x[i].getElementsByTagName("NAME")[0].childNodes[0].nodeValue +
    "</td><td>" +
    x[i].getElementsByTagName("TYPE")[0].childNodes[0].nodeValue +
    "</td><td>" + "£" +
    x[i].getElementsByTagName("PRICE")[0].childNodes[0].nodeValue +
    "</td><td>" + "<button id='add_btn' onclick='calTotal("  + x[i].getElementsByTagName("PRICE")[0].childNodes[0].nodeValue + ");' type='button'>Add</button>" +
    "</td></tr>";;
  }
  //var tot = "<input name='tot' id='tot' type='number' value='' disabled>"
  document.getElementById("demo").innerHTML = table;
//  document.getElementById("demo2").innerHTML = tot;
}



/* -------------------------------------------------------------------------------------- */
/*               Display 1 product at a time with next and prev buttons                   */
/* -------------------------------------------------------------------------------------- */
/*
if(window.XMLHttpRequest)
{
  xmlhttp = new XMLHttpRequest();
}

else {
  xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
}

xmlhttp.open("GET", "../html/XML/products.xml", true);
xmlhttp.send();
xmlDoc = xmlhttp.responseXML;

x = xmlDoc.getElementsByTagName("PRODUCT");
i = 0;

function display()
{
  image = ("<img style='width:60%;' src='" +
  x[i].getElementsByTagName("imageurl")[0].childNodes[0].nodeValue + "'/>");
  name = (x[i].getElementsByTagName("NAME")[0].childNodes[0].nodeValue);
  type = (x[i].getElementsByTagName("TYPE")[0].childNodes[0].nodeValue);
  price = (x[i].getElementsByTagName("PRICE")[0].childNodes[0].nodeValue);
  button = ("<button id='add_btn' onclick='myFunction("  + x[i].getElementsByTagName("PRICE")[0].childNodes[0].nodeValue + ");' type='button'>Add</button>" )

  txt = "Image: " + image + "<br />Name: " + name + "<br />Type: " type + "<br />Price: " + button;
  document.getElementById("demo").innerHTML = txt;

}

function next()
{
  if(i < x.length - 1)
  {
    i++;
    display();
  }
}

function prev()
{
  if(i > 0)
  {
    i--;
    display();
  }
}
*/

/* -------------------------------------------------------------------------------------- */
/*                                     Captcha                                            */
/* -------------------------------------------------------------------------------------- */

var myInput = document.getElementById("serial"),
    serialNumber,
    i,
    number,
    verifOne,
    serial;

function generate() {
    "use strict";

    serial = '';
    serialNumber = "0123456789ABCDEFJHIJKLMNPQRSTUVWXYZabcdefjhijklmnpqrstuvwxyz";

    for (i = 0; i < 4; i = i + 1) {
        number = Math.floor(Math.random() * 60);
        serial = serial + serialNumber.substring(number, number + 1);
    }

    myInput.innerHTML = serial;
}

function verifyCaptcha() {
    "use strict";

    verifOne = document.getElementById("entre").value;

    if (verifOne === serial) {
        alert("Varified!");
    } else {
        alert("Could not be varified, try again!");
    }

}

/* -------------------------------------------------------------------------------------- */
/*                                     Call the functions                                 */
/* -------------------------------------------------------------------------------------- */
function start()
{
  loadXMLDoc();
  //display();
  generate();
}
