#!/bin/bash

services=( KonRoBot.service RPI.service )
systemd_dir=/etc/systemd/system

mkdir -p bin lib

for service in "${services[@]}"
do
    sudo cp utils/"$service" "$systemd_dir"/"$service"
    sudo mkdir "$systemd_dir"/"$service".d
    sudo systemctl daemon-reload
    sudo systemctl enable "$service"
    sudo systemctl start "$service"
done