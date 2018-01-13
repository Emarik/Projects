/* // .ajax way of getting JSON
$.ajax({
    type: 'GET',
    url: 'http://api.openweathermap.org/data/2.5/forecast/daily?q=Salt+Lake+City&units=imperial',
    dataType: 'json',
    success: function (data) {
        postData(data);
    }
});*/

// .getJSON way of getting JSON does the same thing but with less code
//$.getJSON( "http://api.openweathermap.org/data/2.5/forecast/daily?q=Salt+Lake+City&units=imperial",
  $.getJSON(        "api.openweathermap.org/data/2.5/forecast/city?id=524901&APPID=1111111111",
function( data ) {
    postData(data);
});

function postData(weatherData) {
    console.log(weatherData);
    var date = new Date();
    for(var I = 1;I<8;I++) {
        //$('body div:nth-child(I)')
        document.getElementById("place"+I).innerHTML = weatherData.city.name;
        var day = date.getDate()+I-1;
        var month =date.getMonth();
            if(day > 28) {
                if(month == 2) {
                    day = day-28;   
                    month=month+1;
                }
                else if (day > 30 && month == 4 || month == 6 || month == 9 || month == 11) {
                    day = day - 30;
                    month = month+1;
                }
                else if(day > 31) {
                    day = day - 31;
                    month = month + 1;
                }
                
            }
        document.getElementById("day"+I).innerHTML = (month + "/" + day);
        document.getElementById("currentTemp"+I).innerHTML ="Day " + weatherData.list[I-1].temp.day +" &degF";
        document.getElementById("eveTemp"+I).innerHTML ="Eve " + weatherData.list[I-1].temp.eve +" &#176F";
        document.getElementById("maxTemp"+I).innerHTML ="Max " + weatherData.list[I-1].temp.max +" &#176F";
        document.getElementById("minTemp"+I).innerHTML ="Min " + weatherData.list[I-1].temp.min +" &#176F";
         document.getElementById("nightTemp"+I).innerHTML = "Night " + weatherData.list[I-1].temp.night +" &#176F";
        document.getElementById("conditions"+I).innerHTML = weatherData.list[I-1].weather[0].main;
        document.getElementById("conditionsDesc"+I).innerHTML = weatherData.list[I-1].weather[0].description;
        document.getElementById("image"+I).src ="Images/"+ weatherData.list[I-1].weather[0].icon +".png"; 
        
    }
}

$('.content').on("mouseover",function() {
        $(this).css({"border-color": "red", 
             "border-width":"5px", 
             "border-style":"solid"});
    });
    $('.content').on("mouseout",function() {
        $(this).css({"border":"3px solid black"});
    });
    