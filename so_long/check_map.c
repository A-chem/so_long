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

static int flood_fill(size_t x, size_t y, char **map)
{
	int res;
	

	res = 0;
	
	if (map[x][y] == '1' || map[x][y] == 'E' || map[x][y] == 'V')
	{
		if (map[x][y] == 'E')
		{
			map[x][y] = 'V';
			res++;
		}
		return (res);
	}
	if (map[x][y] == 'C' || map[x][y] == 'E')
	{
	   if (map[x + 1][y] == 1 && map[x - 1][y] == 1 
	   		&& map[x][y + 1] == 1 && map[x][y - 1] == 1)
            return (0);
	}
    map[x][y] = 'V';
	res += flood_fill(x + 1, y, map);
	res += flood_fill(x - 1, y, map);
	res += flood_fill(x, y + 1, map);
	res += flood_fill(x, y - 1, map);
	return (res);
}
static int check_ff(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (flood_fill(i, j, map) == 1)
				 	return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_rect(int num_line, char **map)
{
	int	i;
	int j;
	
	i = 0;
	j = 0;
	while (i < num_line)
	{
		if (i != num_line - 1)
		{
			if (ft_strlen(map[i]) != ft_strlen(map[i+1]))
				return (0);
			if (i == 0 || i == num_line - 1)
				while (map[i][j])
				{
					if (map[i][j] != '1')
					return (0);
					j++;
				}
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
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
static int check_wall_elements(int num_lne, char **map)
{
	t_maps t_maps;
	int         i;
	int         j;
	
	i = 0;
	t_maps.count_PE = 0;
	t_maps.count_C = 0;
	while (i < num_lne)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!is_valid_char(map[i][j]))
			return (0);
			if (map[i][j] == 'P' || map[i][j] == 'E')
				t_maps.count_PE++;
			if (map[i][j] == 'C')
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
	if(check_rect(t_maps.num_line, t_maps.map) == 0
		|| check_wall_elements(t_maps.num_line, t_maps.map) == 0)
		return (0);
	if(check_ff(t_maps.map) == 0)
	     return (0);
		return (1);
}
