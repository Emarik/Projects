var numbRand = Math.round(Math.random() * 100);
var output = document.getElementById("output");
console.log(numbRand);
var r = 250;
var g = 150;
var b = 0;



function sendData(form) {
    if(form.inputbox.value == numbRand) {
        output.innerHTML = "CORRECT!!!";
        setInterval(colorChange, 200);
        
    }
    else if(form.inputbox.value > numbRand) {
        output.innerHTML = "Wrong, " + form.inputbox.value + " is too high"
    }
    else{
        output.innerHTML = "Wrong, " + form.inputbox.value + " is too low"
    }
}

function colorChange() {
    var change = document.getElementById("change");
    var rgb = "rgb(" + parseInt(r) + "," + parseInt(g) + "," + parseInt(b) + ")";
    change.style.backgroundColor = rgb;
    if(r == 250) {
        r = 0;
    } else {
        r+=50;
    }
    
    if(g == 250) {
        g = 0;
    } else {
        g+=25;
    }
    
    if(b == 250) {
        b = 0;
    } else {
        b+=10;
    }
    
}