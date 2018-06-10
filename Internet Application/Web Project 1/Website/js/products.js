function loadXMLDoc() {
  var xmlhttp = new XMLHttpRequest();
  xmlhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      myFunction(this);
    }
  };
/* xmlhttp.open("GET", "http://www.w3schools.com/xml/cd_catalog.xml", true); */
  xmlhttp.open("GET", "../html/XML/products.xml", true);
  xmlhttp.send();
}
function myFunction(xml) {
  var i;
  var xmlDoc = xml.responseXML;
  var table="<tr><th>Image</th><th>Name</th><th>Type</th><th>Price</th><th>Order</th></tr>";
  var x = xmlDoc.getElementsByTagName("PRODUCT");
  for (i = 0; i <x.length; i++) {
    table += "<tr><td>" + "<img style='width:60%;' src='" +
    x[i].getElementsByTagName("imageurl")[0].childNodes[0].nodeValue + "'/>" +
    "</td><td>" +
    x[i].getElementsByTagName("NAME")[0].childNodes[0].nodeValue +
    "</td><td>" +
    x[i].getElementsByTagName("TYPE")[0].childNodes[0].nodeValue +
    "</td><td>" +
    x[i].getElementsByTagName("PRICE")[0].childNodes[0].nodeValue +
    "</td><td>" + "<button id='add_btn' type='button'>Add</button>" +
    "</td></tr>";;
  }
  document.getElementById("demo").innerHTML = table;
}

myFunction2(var value){
/*  var table = document.getElementById("demo"), sumVal = 0;

  for(var i = 1; i < table.rows.length; i++)
  {
    sumVal + parseInt(table.row[i].cells[2].innerHTML);
  }

  document.getElementById("sum").innerHTML = "sum value = " + sumVal;
  console.log(sumVal); */

  var sum = 0;

  sum += value;

  window.write(sum);
}
