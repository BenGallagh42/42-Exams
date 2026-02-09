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
} t_map;

typedef struct s_square
{
    int row;
    int col;
    int size;
} t_square;

void print_error(void)
{
    write(2, "map error\n", 10);
}

int ft_atoi(char *str)
{
    int result = 0;
    
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result);
}

t_map *read_map(FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    t_map *map = malloc(sizeof(t_map));
    int i, j, line_len;
    char *p;
    
    if (!map || getline(&line, &len, file) == -1)
        return (free(map), free(line), NULL);
    
    // Parse première ligne
    p = line;
    while (*p == ' ') p++;
    if (*p < '0' || *p > '9')
        return (free(map), free(line), NULL);
    map->rows = ft_atoi(p);
    while (*p >= '0' && *p <= '9') p++;
    while (*p == ' ') p++;
    map->empty = *p++;
    while (*p == ' ') p++;
    map->obstacle = *p++;
    while (*p == ' ') p++;
    map->full = *p;
    
    if (map->empty == map->obstacle || map->empty == map->full || 
        map->obstacle == map->full || map->rows < 1)
        return (free(map), free(line), NULL);
    
    free(line);
    line = NULL;
    
    // Allouer grille
    map->grid = malloc(sizeof(char *) * map->rows);
    if (!map->grid)
        return (free(map), NULL);
    
    map->cols = 0;
    i = 0;
    while (i < map->rows)
    {
        len = 0;
        if (getline(&line, &len, file) == -1)
            return (free(line), NULL);
        
        // Calculer longueur
        line_len = 0;
        while (line[line_len] && line[line_len] != '\n')
            line_len++;
        
        // Vérifier longueur
        if (i == 0)
            map->cols = line_len;
        if (line_len != map->cols)
            return (free(line), NULL);
        
        // Allouer et copier ligne
        map->grid[i] = malloc(map->cols + 1);
        if (!map->grid[i])
            return (free(line), NULL);
        
        j = 0;
        while (j < map->cols)
        {
            if (line[j] != map->empty && line[j] != map->obstacle)
                return (free(line), NULL);
            map->grid[i][j] = line[j];
            j++;
        }
        map->grid[i][map->cols] = '\0';
        i++;
    }
    free(line);
    
    if (map->cols < 1)
        return (NULL);
    return (map);
}

int is_valid(t_map *map, int row, int col, int size)
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

void print_map(t_map *map)
{
    int i = 0;
    
    while (i < map->rows)
    {
        write(1, map->grid[i], map->cols);
        write(1, "\n", 1);
        i++;
    }
}

void process_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    t_map *map;
    t_square sq;
    
    if (!file)
    {
        print_error();
        return;
    }
    map = read_map(file);
    fclose(file);
    if (!map)
    {
        print_error();
        return;
    }
    sq = find_biggest_square(map);
    fill_square(map, sq);
    print_map(map);
}

void process_stdin(void)
{
    t_map *map = read_map(stdin);
    t_square sq;
    
    if (!map)
    {
        print_error();
        return;
    }
    sq = find_biggest_square(map);
    fill_square(map, sq);
    print_map(map);
}

int main(int argc, char **argv)
{
    int i;
    
    if (argc == 1)
        process_stdin();
    else
    {
        i = 1;
        while (i < argc)
        {
            process_file(argv[i]);
            if (i < argc - 1)
                write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}