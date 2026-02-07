#include <stdlib.h>
#include <unistd.h>

typedef struct s_grid
{
    int width;
    int height;
    char **cells;
}   t_grid;

t_grid *create_grid(int width, int height)
{
    int i, j;
    t_grid *grid = malloc(sizeof(t_grid));
    if (!grid)
        return (NULL);

    grid->width = width;
    grid->height = height;
    grid->cells = malloc(sizeof(char *) * height);
    if (!grid->cells)
        return (free(grid), NULL);
    
    i = -1;
    while (++i < height)
    {
        grid->cells[i] = malloc(width);
        if (!grid->cells[i])
            return (NULL);
        j = -1;
        while (++j < width)
            grid->cells[i][j] = 0;
    }
    return (grid);
}

void print_grid(t_grid *grid)
{
    int i, j;
    
    i = -1;
    while (++i < grid->height)
    {
        j = -1;
        while (++j < grid->width)
            write(1, grid->cells[i][j] ? "O" : " ", 1);
        write(1, "\n", 1);
    }
}

void process_commands(t_grid *grid)
{
    int x = 0, y = 0, drawing = 0;
    char cmd;

    while (read(0, &cmd, 1) > 0)
    {
        if (cmd == 'x')
            drawing = !drawing;
        else if (cmd == 'w' && y > 0)
        {
            if (drawing) grid->cells[y][x] = 1;
            y--;
        }
        else if (cmd == 's' && y < grid->height - 1)
        {
            if (drawing) grid->cells[y][x] = 1;
            y++;
        }
        else if (cmd == 'a' && x > 0)
        {
            if (drawing) grid->cells[y][x] = 1;
            x--;
        }
        else if (cmd == 'd' && x < grid->width - 1)
        {
            if (drawing) grid->cells[y][x] = 1;
            x++;
        }
    }
    if (drawing)
        grid->cells[y][x] = 1;
}

int count_neighbors(t_grid *grid, int y, int x)
{
    int count = 0, i, j;
    
    i = y - 1;
    while (i <= y + 1)
    {
        j = x - 1;
        while (j <= x + 1)
        {
            if (i >= 0 && i < grid->height && j >= 0 && j < grid->width)
                if (!(i == y && j == x) && grid->cells[i][j])
                    count++;
            j++;
        }
        i++;
    }
    return (count);
}

void run_iterations(t_grid *grid, int iterations)
{
    char **next;
    int i, j, iter, neighbors;
    
    if (iterations == 0)
        return;
    next = malloc(sizeof(char *) * grid->height);
    i = -1;
    while (++i < grid->height)
        next[i] = malloc(grid->width);

    iter = -1;
    while (++iter < iterations)
    {
        i = -1;
        while (++i < grid->height)
        {
            j = -1;
            while (++j < grid->width)
            {
                neighbors = count_neighbors(grid, i, j);
                if (grid->cells[i][j])
                    next[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
                else
                    next[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }

        i = -1;
        while (++i < grid->height)
        {
            j = -1;
            while (++j < grid->width)
                grid->cells[i][j] = next[i][j];
        }
    }
}

int main(int argc, char **argv)
{
    t_grid *grid;
    
    if (argc != 4)
        return (1);
    grid = create_grid(atoi(argv[1]), atoi(argv[2]));
    if (!grid)
        return (1);
    process_commands(grid);
    run_iterations(grid, atoi(argv[3]));
    print_grid(grid);
    return (0);
}