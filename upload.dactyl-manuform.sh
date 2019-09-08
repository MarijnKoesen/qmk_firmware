#!/bin/bash

# Like /dev/cu.usbmodem1421
PORT=$1
FIRMWARE=/Users/marijn/Development/github.com/tshort/qmk_firmware/dactyl-manuform_4x5-default.hex
FIRMWARE=/Users/marijn/Development/github.com/tshort/qmk_firmware/dactyl-manuform_mk.hex
FIRMWARE=/Users/marijn/Development/github.com/tshort/qmk_firmware/dactyl-manuform_5x6-default.hex
FIRMWARE=/Users/marijn/Development/github.com/marijnkoesen/qmk_firmware/handwired_dactyl_manuform_4x6_mkdev.hex
FIRMWARE=/Users/marijn/Development/github.com/marijnkoesen/qmk_firmware/.build/handwired_dactyl_manuform_4x6_mkdev.hex

if [ "$PORT" = "" ]; then
    PORT=$(ls -1 "/dev/cu.usb*" 2>/dev/null)
fi

if [ "$PORT" = "" ]; then
    echo "No arduino found.."
    exit -1;
fi

echo "Using port: $PORT"
#/Users/marijn/Downloads/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude -C/Users/marijn/Downloads/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf -v -patmega32u4 -cavr109 -P$1 -b57600 -D -Uflash:w:/Users/marijn/Development/github.com/tshort/qmk_firmware/dactyl-manuform_4x6-default.hex:i 

/Users/marijn/Downloads/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude -C/Users/marijn/Downloads/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf -v -patmega32u4 -cavr109 -P$PORT -b57600 -D -Uflash:w:$FIRMWARE:i 
