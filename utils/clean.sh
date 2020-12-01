#!/bin/bash

services=( KonRoBot.service RPI.service )
systemd_dir=/etc/systemd/system

for service in "${services[@]}"
do
    sudo systemctl stop "$service"
    sudo systemctl disable "$service"
    sudo rm -rf "$systemd_dir"/"$service"*
    sudo systemctl daemon-reload
done