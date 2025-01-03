#include "so_long.h"
int main(int argc, char **argv)
{
    char *pat_str;

    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    pat_str = argv[1];
    if(check_map(pat_str) == 0)
    {
        write(1, "Your map not valid !!!\n", 24);
        return (0);
    }
    else
    {
        write(1, "Your map is valid !!!\n", 23);
        return (0);
    }
    return 0;
}
