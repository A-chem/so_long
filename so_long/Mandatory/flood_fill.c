/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:20:36 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/07 17:27:50 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(size_t x, size_t y, size_t num_line, char **map)
{
	if (x < 0 || y < 0 || x > num_line || y > ft_strlen(map[0]))
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V' || map[x][y] == 'E')
		return ;
	map[x][y] = 'V';
	flood_fill(x + 1, y, num_line, map);
	flood_fill(x - 1, y, num_line, map);
	flood_fill(x, y + 1, num_line, map);
	flood_fill(x, y - 1, num_line, map);
}

static int	test_ff(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_ff(t_game g)
{
	size_t	i;
	size_t	j;
	char	**copy_map;

	i = 0;
	copy_map = ft_split(g.str, '\n');
	if (!copy_map)
		return (0);
	while (copy_map[i])
	{
		j = 0;
		while (copy_map[i][j])
		{
			if (copy_map[i][j] == 'P')
			{
				flood_fill(i, j, g.num_line, copy_map);
				if (test_ff(copy_map) == 0)
					return (free_map(copy_map), 0);
			}
			j++;
		}
		i++;
	}
	return (free_map(copy_map), free(g.str), 1);
}
