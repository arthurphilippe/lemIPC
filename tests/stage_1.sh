#!/bin/zsh

##
## EPITECH PROJECT, 2018
## PSU_lemipc_2017
## File description:
## stage_1
##

IPCS_START_COUNT=$(ipcs | wc -l)

./lemipc .gitignore 1 &
./lemipc .gitignore 1 &
./lemipc .gitignore 1 &
./lemipc .gitignore 1 &
./lemipc .gitignore 1 &
./lemipc .gitignore 1 &
./lemipc .gitignore 6 &
./lemipc .gitignore 6 &
./lemipc .gitignore 6 &
./lemipc .gitignore 6 &
./lemipc .gitignore 6 &
./lemipc .gitignore 6 &
./lemipc .gitignore 2 &
./lemipc .gitignore 2 &
./lemipc .gitignore 2 &
./lemipc .gitignore 2 &
./lemipc .gitignore 2 &
./lemipc .gitignore 2 &
./lemipc .gitignore 2 &
./lemipc .gitignore 2 &
./lemipc .gitignore 5 &
./lemipc .gitignore 5 &
./lemipc .gitignore 3 &
./lemipc .gitignore 3 &
./lemipc .gitignore 3 &
./lemipc .gitignore 3 &

while [ "$IPCS_START_COUNT" -ne $(ipcs | wc -l) ]
do
	sleep 1
done

echo "$0 exited"
