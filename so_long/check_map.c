/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:49:33 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/03 14:53:01 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(size_t x, size_t y,size_t num_line, char **map)
{
    if (x < 0 || y < 0 || x > num_line || y > ft_strlen(map[0]))
		return ;
		if (map[x][y] == '1' || map[x][y] == 'V')
			return ;

		map[x][y] = 'V';
		flood_fill(x + 1, y,num_line, map);
		flood_fill(x - 1, y,num_line,  map);
		flood_fill(x, y + 1,num_line, map);
		flood_fill(x, y - 1,num_line, map);
}
static int test_ff(char **map)
{
	size_t i;
	size_t j;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
static int check_ff(t_maps t_maps)
{
	size_t i;
	size_t j;
	char **copy_map;

	i = 0;
	copy_map = ft_split(t_maps.str, '\n');
	if(!copy_map)
		return (0);
	while (copy_map[i])
	{
		j = 0;
		while (copy_map[i][j])
		{
			if (copy_map[i][j] == 'P')
			{
				flood_fill(i, j, t_maps.num_line, copy_map);
				if(test_ff(copy_map) == 0) 
				  	return (0);
				break;
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_rect(t_maps t_maps)
{
	size_t	i;
	size_t j;
	
	i = 0;
	j = 0;
	while (i < t_maps.num_line)
	{
		if (i != t_maps.num_line - 1)
		{
			if (ft_strlen(t_maps.map[i]) != ft_strlen(t_maps.map[i+1]))
				return (0);
			if (i == 0 || i == t_maps.num_line - 1)
				while (t_maps.map[i][j])
				{
					if (t_maps.map[i][j] != '1')
					return (0);
					j++;
				}
			if (t_maps.map[i][0] != '1' 
				|| t_maps.map[i][ft_strlen(t_maps.map[i]) - 1] != '1')
			return (0);
		}
		i++;
	}
	return (1);
}
static int is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C');
}
static int check_wall_elements(t_maps t_maps)
{
	size_t         i;
	size_t         j;
	
	i = 0;
	t_maps.count_PE = 0;
	t_maps.count_C = 0;
	while (i < t_maps.num_line)
	{
		j = 0;
		while (t_maps.map[i][j] != '\0')
		{
			if (!is_valid_char(t_maps.map[i][j]))
			return (0);
			if (t_maps.map[i][j] == 'P' || t_maps.map[i][j] == 'E')
				t_maps.count_PE++;
			if (t_maps.map[i][j] == 'C')
				t_maps.count_C++;
			j++;
		}
		i++;
	}
	if (t_maps.count_PE != 2 || t_maps.count_C < 1)
		return (0);
	return (1);
}
int	check_map(char *pat_str)
{
	t_maps t_maps;
	char    *line;
     
	t_maps.fd  = open(pat_str, O_RDONLY);
	if (t_maps.fd == -1)
		return (0);
	t_maps.num_line = 0;
	t_maps.str = NULL;
	while (1)
	{
		line = get_next_line(t_maps.fd);
		if (!line)
			break ;
		t_maps.str = ft_strjoin(t_maps.str, line);
		if (!t_maps.str || line[0] == '\n')
			return (0);
		t_maps.num_line++;
	}
	t_maps.map = ft_split(t_maps.str, '\n');
	if((check_rect(t_maps) == 0) || check_wall_elements(t_maps) == 0)
		return (0);
	if(check_ff(t_maps) == 0)
	     return (0);
		return (1);
}
