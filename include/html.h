#include "main.h"

//int deg = analogReadToDegrees(analogRead(tempPin));
const char html1[] = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Proto</title>
    <style>
        html {
            font-size: x-large;
        }

        button {
            color: black;
            padding: 16px 32px;
            text-align: center;
            font-size: 16px;
            margin: 4px 2px;
        }

        .box {
            width: fit-content;
            padding: 10px;
            border-radius: 5px;
            margin-left: auto;
            margin-right: auto;
            text-align: center;
        }

        #slider {
            width: 100%;
        }

        a {
            text-decoration: none;
            color: black;
        }
    </style>
</head>

<body>
    <h2 style="text-align: center;">Interface</h2>
    <hr>
    <div>
        <div class="box">Current temp: <span id="currentTemp">)=====";

const char html2[] = R"=====(</span>°c
            <br>
        </div>
        <div class="box">
            <button onclick="getTemp()">Refresh Temp</button>
        </div>
        <div class="box">Target temp: <span id="setTemp">)=====";

const char html3[] = R"=====(</span>°c</div>
        <div class="box" style="width: 85%;">
            <input type="range" min="40" max="65" value="40" id="slider">
            <div id="targetTemp">40</div>
            <button onclick="setTarget()">Set Target</button>
        </div>
    </div>
    <script>
        const $ = (id) => { return document.getElementById(id) };
        const slider = $("slider");
        const currentTemp = $("currentTemp");
        const targetTemp = $("targetTemp");
        const setTemp = $("setTemp");

        slider.oninput = () => {
            targetTemp.innerHTML = slider.value + "";

        }
        function setTarget() {
            location.href = "/val/" + targetTemp.innerHTML;
        }
        function getTemp() {
            location.href = "/"
        }
    </script>
</body>

</html>

)=====";