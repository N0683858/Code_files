


//put the code inside products.js so that all the js code for order.html is together
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
        alert("good");
    } else {
        alert("bad captcha try again");
    }

}
