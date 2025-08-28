#!/bin/bash

bat0=$(cat /sys/class/power_supply/BAT0/capacity)
stat0=$(cat /sys/class/power_supply/BAT0/status)
bat1=$(cat /sys/class/power_supply/BAT1/capacity)
stat1=$(cat /sys/class/power_supply/BAT1/status)

icon() {
  case "$1" in
    Charging) echo " ";;      
    Discharging) echo " ";;  
    Full) echo " ";;        
    *) echo " ";;         
  esac
}

echo "$(icon $stat0)$bat0% $(icon $stat1)$bat1%"

