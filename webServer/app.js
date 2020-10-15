var express = require('express');
var router = express.Router();
var fs = require('fs');
var path = require('path');
var routes = require('./routes/index');
var app = express();

app.use(express.urlencoded({ extended: true }))
app.use(express.json());
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));
app.use('/', routes);
app.use(express.static(path.join(__dirname, 'public')));
app.listen(85);
