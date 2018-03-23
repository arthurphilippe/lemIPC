#!/bin/bash

##
## EPITECH PROJECT, 2018
## PSU_lemipc_2017
## File description:
## stage_1
##

IPCS_START_COUNT=$(ipcs | wc -l)
TEMPO=20

./lemipc .gitignore 1 $TEMPO &
sleep 1
./lemipc .gitignore 1 "$TEMPO" &
./lemipc .gitignore 1 "$TEMPO" &
./lemipc .gitignore 1 "$TEMPO" &
./lemipc .gitignore 6 "$TEMPO" &
./lemipc .gitignore 6 "$TEMPO" &
./lemipc .gitignore 6 "$TEMPO" &
./lemipc .gitignore 6 "$TEMPO" &
./lemipc .gitignore 6 "$TEMPO" &
./lemipc .gitignore 6 "$TEMPO" &
./lemipc .gitignore 2 "$TEMPO" &
./lemipc .gitignore 2 "$TEMPO" &
./lemipc .gitignore 2 "$TEMPO" &
./lemipc .gitignore 2 "$TEMPO" &
./lemipc .gitignore 2 "$TEMPO" &
./lemipc .gitignore 2 "$TEMPO" &
./lemipc .gitignore 2 "$TEMPO" &
./lemipc .gitignore 2 "$TEMPO" &
./lemipc .gitignore 5 "$TEMPO" &
./lemipc .gitignore 5 "$TEMPO" &
./lemipc .gitignore 3 "$TEMPO" &
./lemipc .gitignore 3 "$TEMPO" &
./lemipc .gitignore 3 "$TEMPO" &
./lemipc .gitignore 3 "$TEMPO" &

while [ "$IPCS_START_COUNT" -ne $(ipcs | wc -l) ]
do
	sleep 1
done

echo "$0 exited"
