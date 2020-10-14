var express = require('express');
var router = express.Router();
var promises = require('fs').promises;

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

module.exports = router;
