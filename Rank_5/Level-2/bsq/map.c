#include "bsq.h"

static int ft_atoi(char *str)
{
    int result;
    
    result = 0;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result);
}

static int parse_first_line(char *line, t_map *map)
{
    int i;
    
    i = 0;
    while (line[i] == ' ')
        i++;
    if (line[i] < '0' || line[i] > '9')
        return (0);
    map->rows = ft_atoi(&line[i]);
    while (line[i] >= '0' && line[i] <= '9')
        i++;
    while (line[i] == ' ')
        i++;
    map->empty = line[i++];
    while (line[i] == ' ')
        i++;
    map->obstacle = line[i++];
    while (line[i] == ' ')
        i++;
    map->full = line[i];
    if (map->empty == map->obstacle || map->empty == map->full || 
        map->obstacle == map->full || map->rows < 1)
        return (0);
    return (1);
}

static int get_line_len(char *line)
{
    int len;
    
    len = 0;
    while (line[len] && line[len] != '\n')
        len++;
    return (len);
}

static int validate_line(char *line, t_map *map, int len)
{
    int j;
    
    j = 0;
    while (j < len)
    {
        if (line[j] != map->empty && line[j] != map->obstacle)
            return (0);
        j++;
    }
    return (1);
}

t_map *read_map(FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    t_map *map;
    int i, line_len;
    
    map = malloc(sizeof(t_map));
    if (!map || getline(&line, &len, file) == -1 || !parse_first_line(line, map))
    {
        free(map);
        free(line);
        return (NULL);
    }
    free(line);
    line = NULL;
    map->grid = malloc(sizeof(char *) * map->rows);
    if (!map->grid)
        return (free(map), NULL);
    map->cols = 0;
    i = 0;
    while (i < map->rows)
    {
        len = 0;
        if (getline(&line, &len, file) == -1)
            return (free(line), free_map(map), NULL);
        line_len = get_line_len(line);
        if (i == 0)
            map->cols = line_len;
        if (line_len != map->cols || !validate_line(line, map, line_len))
            return (free(line), free_map(map), NULL);
        map->grid[i] = malloc(map->cols + 1);
        if (!map->grid[i])
            return (free(line), free_map(map), NULL);
        int j = 0;
        while (j < map->cols)
        {
            map->grid[i][j] = line[j];
            j++;
        }
        map->grid[i][map->cols] = '\0';
        i++;
    }
    free(line);
    if (map->cols < 1)
        return (free_map(map), NULL);
    return (map);
}