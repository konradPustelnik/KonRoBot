#!/bin/bash

systemd_dir=/etc/systemd/system
services=( KonRoBot RPI )

for service in "${services[@]}"
do
    sudo cp "$service".service "$systemd_dir"/"$service".service
    sudo mkdir "$systemd_dir"/"$service".service.d
    sudo systemctl daemon-reload
    sudo systemctl enable "$service"
    sudo systemctl start "$service"
done
