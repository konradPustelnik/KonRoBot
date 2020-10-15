$(function () {
    $('#makeSignal').click(() => {
        $.ajax({
            type: "POST",
            url: '/action',
            dataType: 'json',
            data: {cmd: "makeSignal"},
        });
    });

    $('#drawRectangle').click(() => {
        $.ajax({
            type: "POST",
            url: '/action',
            dataType: 'json',
            data: {cmd: "drawRectangle"},
        });
    });
    $('#driveIndependentlyWithManualSensor').click(() => {
        $.ajax({
            type: "POST",
            url: '/action',
            dataType: 'json',
            data: {cmd: "driveIndependentlyWithManualSensor"},
        });
    });
    $('#driveManually').click(() => {
        $.ajax({
            type: "POST",
            url: '/action',
            dataType: 'json',
            data: {cmd: "driveManually"},
        });
    });
    $('#driveIndependentlyWithSensor').click(() => {
        $.ajax({
            type: "POST",
            url: '/action',
            dataType: 'json',
            data: {cmd: "driveIndependentlyWithSensor"},
        });
    });
    $('#stop').click(() => {
        $.ajax({
            type: "POST",
            url: '/action',
            dataType: 'json',
            data: {cmd: "stop"},
        });
    });
});
