var express = require('express');
var router = express.Router();
var promises = require('fs').promises;
var fs = require('fs');

const bodyParser = require("body-parser");
var exec = require('child_process').exec, child;

router.get('/', function(req, res, next) {
    if (req.accepts('text/html')) {
        Promise.all([
            promises.readFile('/home/pi/KonRoBot/sensor', { encoding: 'ascii' }),
        ]).then(([sensorValue]) => res.render('index', {value: sensorValue}));
    }
    else {
        res.status(400);
        res.send('error');
    }
});

router.post('/action', function(req, res, next) {
    if (req.accepts('application/json')) {
        if (req.body.cmd  == "makeSignal"){
            exec("echo 1 > /home/pi/KonRoBot/machineState");
        }
        else if (req.body.cmd  == "drawRectangle"){
            exec("echo 2 > /home/pi/KonRoBot/machineState");
        }
        else if (req.body.cmd  == "driveIndependentlyWithManualSensor"){
            exec("echo 3 > /home/pi/KonRoBot/machineState");
        }
        else if (req.body.cmd  == "driveManually"){
            exec("echo 4 > /home/pi/KonRoBot/machineState");
        }
        else if (req.body.cmd  == "driveIndependentlyWithSensor"){
            exec("echo 5 > /home/pi/KonRoBot/machineState");
        }
        else if (req.body.cmd  == "stop"){
            exec("echo 6 > /home/pi/KonRoBot/machineState");
        }
        else if (req.body.cmd  == "goStraight"){
            exec("echo 8 > /home/pi/KonRoBot/manualControl");
        }
        else if (req.body.cmd  == "turnLeft"){
            exec("echo 4 > /home/pi/KonRoBot/manualControl");
        }
        else if (req.body.cmd  == "stopDM"){
            exec("echo 5 > /home/pi/KonRoBot/manualControl");
        }
        else if (req.body.cmd  == "turnRight"){
            exec("echo 6 > /home/pi/KonRoBot/manualControl");
        }
        else if (req.body.cmd  == "goBack"){
            exec("echo 2 > /home/pi/KonRoBot/manualControl");
        }
        else if (req.body.cmd  == "speed"){
            exec("echo " + req.body.speed + " > /home/pi/KonRoBot/speed");
        }
    }
});

module.exports = router;
