#!/bin/bash

make clean
make
sudo insmod mymodule.ko
ls /dev | grep "wkdevice"
./main
sudo rmmod mymodule
make clean
sudo dmesg