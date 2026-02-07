#include "bsq.h"

static void process_file(char *filename)
{
    FILE *file;
    t_map *map;
    t_square sq;
    
    file = fopen(filename, "r");
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
    free_map(map);
}

static void process_stdin(void)
{
    t_map *map;
    t_square sq;
    
    map = read_map(stdin);
    if (!map)
    {
        print_error();
        return;
    }
    sq = find_biggest_square(map);
    fill_square(map, sq);
    print_map(map);
    free_map(map);
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