#include "bsq.h"

void free_map(t_map *map)
{
    int i;
    
    if (!map)
        return;
    if (map->grid)
    {
        i = 0;
        while (i < map->rows)
        {
            if (map->grid[i])
                free(map->grid[i]);
            i++;
        }
        free(map->grid);
    }
    free(map);
}

void print_error(void)
{
    write(2, "map error\n", 10);
}

void print_map(t_map *map)
{
    int i;
    
    i = 0;
    while (i < map->rows)
    {
        write(1, map->grid[i], map->cols);
        write(1, "\n", 1);
        i++;
    }
}