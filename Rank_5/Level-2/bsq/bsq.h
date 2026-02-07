#ifndef BSQ_H
#define BSQ_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_map
{
    int rows;
    int cols;
    char empty;
    char obstacle;
    char full;
    char **grid;
}   t_map;

typedef struct s_square
{
    int row;
    int col;
    int size;
}   t_square;

// map.c
t_map   *read_map(FILE *file);

// solve.c
t_square    find_biggest_square(t_map *map);
void        fill_square(t_map *map, t_square sq);

// utils.c
void    free_map(t_map *map);
void    print_map(t_map *map);
void    print_error(void);

#endif