#!/bin/bash
CASE=$1
CNT=$2

echo $CNT > input/$CASE
jot -r $CNT 1 10000 | sort -R >> input/$CASE

tail -n +2  input/$CASE | sort -h > output/$CASE
