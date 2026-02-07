#include "bsq.h"

static int is_valid(t_map *map, int row, int col, int size)
{
    int i, j;
    
    if (row + size > map->rows || col + size > map->cols)
        return (0);
    i = row;
    while (i < row + size)
    {
        j = col;
        while (j < col + size)
        {
            if (map->grid[i][j] == map->obstacle)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

t_square find_biggest_square(t_map *map)
{
    t_square best = {0, 0, 0};
    int i, j, size, max_size;
    
    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->cols)
        {
            max_size = (map->rows - i < map->cols - j) ? 
                       map->rows - i : map->cols - j;
            size = 1;
            while (size <= max_size)
            {
                if (is_valid(map, i, j, size))
                {
                    if (size > best.size)
                    {
                        best.row = i;
                        best.col = j;
                        best.size = size;
                    }
                }
                else
                    break;
                size++;
            }
            j++;
        }
        i++;
    }
    return (best);
}

void fill_square(t_map *map, t_square sq)
{
    int i, j;
    
    i = sq.row;
    while (i < sq.row + sq.size)
    {
        j = sq.col;
        while (j < sq.col + sq.size)
        {
            map->grid[i][j] = map->full;
            j++;
        }
        i++;
    }
}