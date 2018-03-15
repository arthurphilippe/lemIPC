/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** key_get
*/

#include "lemipc.h"

/*
** Return a key to use with IPC functions
*/
key_t key_get(const char *path)
{
	return (ftok(path, PROJ_ID));
}
