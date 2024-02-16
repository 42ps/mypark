#!/bin/bash

list=$(find input -type f | xargs basename)

for e in $list
do
	cargo run <input/$e 2>/dev/null | diff - output/$e 
done

if [ $? -eq 0 ]; then
  printf "\033[32m Success!!!!! \033[0m\n"
else 
  printf "\033[31m Fail!!!!! \033[0m\n"
fi