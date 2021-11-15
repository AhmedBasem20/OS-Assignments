#!/usr/bin/bash
temp <<<
read temp
(( temp = temp*9/5 + 32 ))
echo "Temperature = $temp Fahrenheit degree"
