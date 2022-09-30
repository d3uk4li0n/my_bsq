#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../include/map.h"

#ifndef MY_BSQ_H
#define MY_BSQ_H

int read_size(char *);
void my_bsq(char *);
char_map get_map(char *);
void free_map(char_map);
void print_map(char_map);

#endif