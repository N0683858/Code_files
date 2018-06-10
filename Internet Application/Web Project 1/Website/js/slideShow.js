
/* -------------------------------------------------------------------------------------- */
/*               Previrw images with thumbnail                                            */
/* -------------------------------------------------------------------------------------- */
//followed YT tutorial: How to make Image Slider with with thumnail preview (JS)

/*var lastImg = 1; //Set initial thumbnail and preview
document.getElementById(0).src = document.getElementById(lastImg).src;
document.getElementById(lastImg).className = "thumb selected";

function preview(img) {
    document.getElementById(lastImg).className = "thumb normal";
    img.className = "thumb selected";
    document.getElementById(0).src = img.src;
    lastImg = img.id
}
*/

var index=0;
var titles=[1,2,3];

function moveToNextSlide()
{
if (index >= titles.length - 1)
{
index=-1;
}
var img = document.getElementById("img1");
index = index + 1;
var slideName="images/img" + titles[index] + ".jpg";
img.src=slideName;
}

function moveToPrevSlide()
{
if (index >= titles.length)
{
index=+1;
}
var img = document.getElementById("img1");
index = index - 1;
var slideName="images/img" + titles[index] + ".jpg";
img.src=slideName;
}

function random()
{

  var img = document.getElementById("img1");
  index = Math.floor((Math.random() * 3) + 0);
  var slideName="images/img" + titles[index] + ".jpg";
  img.src=slideName;
}

var ct = 0;
var imgs = new Array("../html/images/img1.jpg, ../html/images/img2.jpg, ../html/images/img3.jpg");
setTimeout("progress()",3000);

function progress() {
   if (ct < 3) {
      document.images[0].src=imgs[ct];
      ct++;
      setTimeout("progress()",3000);
   }
}
