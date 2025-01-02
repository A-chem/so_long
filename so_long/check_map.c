#include "so_long.h"



int check_rect_wall_elements(int num_len, char **maps) {
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < num_len)
    {
     if(i == 0 || i == num_len - 1)
    {
     while (maps[i][j] != '\0')
        {
            if (maps[i][j] != '1')
                return (0);
            j++;
        }
    }
    else
    {
        while (maps[i][j] != '\0')
        {
        if (maps[i][0] != '1' || maps[i][ft_strlen(maps[i] - 1)] != '1')
                return (0);
        if(maps[i][j] == '1' || maps[i][j] == '0' || maps[i][j] == 'C' || maps[i][j] == 'E' || maps[i][j] == 'P')
            j++;
        }
        
    }
     
       j = 0;
    }
    
    return (1);
}
int check_map(char *pat_str)
{
    int fd;
    int num_line;
    char *str;
    char **map;
  
    fd  = open(pat_str, O_RDONLY);
    if (fd == -1)
        return (0);
 num_line = 0;
 str = NULL;
while(1)
{
    str = get_next_line(fd);
    if (!str)
        break;
        num_line++;
}
 map = ft_split(str, '\n');
if(check_rect_wall_elements(num_line, map) == 0) 
    return(0);
    return (1);
}
//Check for rectangular shape by verifying that all rows are of the same length.
//Ensure the outer boundary of the map consists of 1 (walls).
//Parse through the map to count the occurrences of P, E, and C. If there are any duplicates or missing essential elements, throw an error.
//Implement a flood fill algorithm to check if there is a valid path from P to E. This can be done using Depth-First Search (DFS) or Breadth-First Search (BFS).