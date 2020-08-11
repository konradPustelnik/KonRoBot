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

while getopts "p:h" flag; do
   case "$flag" in
   p) PIN="$OPTARG";;
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
    echo $1 > /sys/class/gpio/$2
}

gpio_pin_direction() {
    echo $1 > /sys/class/gpio/gpio$2/direction
}

gpio_pin_value() {
    echo $1 > /sys/class/gpio/gpio$2/value
}

turn_on_sleep_turn_off() {
    gpio_pin_access "$1" "export"
    gpio_pin_direction "out" "$1"
    gpio_pin_value "1" "$1"
    sleep $TIMEOUT
}

turn_on_sleep_turn_off $PIN
