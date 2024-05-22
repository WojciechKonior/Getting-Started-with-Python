#!/bin/bash

make clean
make
sudo insmod mymodule.ko
sudo rmmod mymodule
sudo dmesg