/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:39:54 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/09 13:40:02 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}

void	cleanup_game(t_game *g)
{
	if (g->str)
		free(g->str);
	if (g->map)
		free_map(g->map);
	if (g->fd >= 0)
		close(g->fd);
}

int	exit_window(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
	return (0);
}
