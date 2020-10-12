#!/bin/bash -Eeu

die() {
    echo "ERROR: $*" >&2
    exit 1
}
trap 'die "\"$BASH_COMMAND\" returned $? at $0:$LINENO"' ERR INT

die_usage() {
   cat >&2 <<__EOF__
Usage: $0 [OPTIONS...] <timeout>
   -p             turn on/off the diode <-p 21>
    
__EOF__
   exit 1
}

declare -a PIN

while getopts "p:t:h" flag; do
   case "$flag" in
   p)   PIN="$OPTARG";;
   t)   PIN=($2 $3 $4); shift 2;;
   h) die_usage;;
   [?]) die_usage;;
   esac
done

shift $((OPTIND-1))

if [ $# -ne 1 ]; then
   die_usage
fi

TIMEOUT="$1"

trap 'gpio_pin_access "$PIN" "unexport"' EXIT

gpio_pin_access() {
    for i in ${PIN[@]}
    do
        echo $i > /sys/class/gpio/$2
    done 
}

gpio_pin_direction() {
    for i in ${PIN[@]}
    do
        echo $1 > /sys/class/gpio/gpio$i/direction
    done 
}

prepare_pin(){
    gpio_pin_access "$1" "export"
    gpio_pin_direction "out" "$1"
}

gpio_pin_value() {
    echo $1 > /sys/class/gpio/gpio$2/value
}

turn_on_sleep_turn_off() {
    prepare_pin "$1"
    gpio_pin_value "1" "$1"
    sleep $TIMEOUT
}

traffic_lights(){
    prepare_pin "$1"
    gpio_pin_value "1" "${PIN[0]}"
    sleep $TIMEOUT
    gpio_pin_value "1" "${PIN[1]}"
    sleep 1
    gpio_pin_value "0" "${PIN[0]}"
    gpio_pin_value "0" "${PIN[1]}"
    gpio_pin_value "1" "${PIN[2]}"
    sleep $TIMEOUT
    gpio_pin_value "0" "${PIN[2]}"
    gpio_pin_value "1" "${PIN[1]}"
    sleep 1
    gpio_pin_value "0" "${PIN[1]}"
    gpio_pin_value "1" "${PIN[0]}"
    sleep $TIMEOUT
}

if [[ ${#PIN[@]} == 1 ]];then
    turn_on_sleep_turn_off $PIN
elif [[ ${#PIN[@]} == 3 ]];then
    traffic_lights ${PIN[@]}
fi

