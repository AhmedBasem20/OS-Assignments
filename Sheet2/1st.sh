#!/usr/bin/bash
read s
((h = (s - s%3600)/3600))
   (( s = s%3600))
    ((m = (s-s%60)/60))
   (( s = s%60))
echo "$h : $m : $s"
