/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "lemipc.h"

int main(void)
{
	dprintf(1, "hi\n");
	lem_start(FTOK_FILE_PATH, 1);
	ipc_delete(FTOK_FILE_PATH);
}
