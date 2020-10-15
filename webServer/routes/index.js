var express = require('express');
var router = express.Router();
var promises = require('fs').promises;
var fs = require('fs');

const bodyParser = require("body-parser");
var exec = require('child_process').exec, child;

router.get('/', function(req, res, next) {
    if (req.accepts('text/html')) {
        Promise.all([
            promises.readFile('/home/pi/sensor', { encoding: 'ascii' }),
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
            exec("/home/pi/RPI/KonRoBot/app/makeSignal");
            //console.log("makeSignal", req.body.cmd);
        }
        else if (req.body.cmd  == "drawRectangle"){
            exec("/home/pi/RPI/KonRoBot/app/drawRectangle");
        }
        else if (req.body.cmd  == "driveIndependentlyWithManualSensor"){
            exec("/home/pi/RPI/KonRoBot/app/driveIndependentlyWithManualSensor");
        }
        else if (req.body.cmd  == "driveManually"){
            exec("/home/pi/RPI/KonRoBot/app/driveManually");
        }
        else if (req.body.cmd  == "driveIndependentlyWithSensor"){
            exec("/home/pi/RPI/KonRoBot/app/driveIndependentlyWithSensor");
        }
        else if (req.body.cmd  == "stop"){
            exec("gpio unexportall");
        }
    }
});

module.exports = router;
