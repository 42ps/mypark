#!/bin/bash
run_cmd=$1

list=$(find input -type f | sed  's/input\///g' | sort)

for e in $list
do
  echo -n "$e "
	result=$($run_cmd <input/$e 2>/dev/null | diff - output/$e 2>&1)

  if [ $? -eq 0 ]; then
    printf "\033[32m Success!!!!! \033[0m\n"
  else 
    printf "\033[31m Fail!!!!! \033[0m\n"
    echo $result
  fi
done
