/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:16:57 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/07 16:27:46 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static int	is_valid_map( char *pat_str, t_game *g)
{
	if (ft_strncmp(pat_str + ft_strlen(pat_str) - 4, ".ber", 4) != 0)
	{
		perror("Error Extention (.ber). Sorry");
		return (0);
	}
	if (check_map(pat_str, g) == 0)
	{
		perror("Your map not valid !!!. Sorry");
		return (0);
	}
	else
		return (1);
}

static int	is_graphic_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		return (0);
	// static int	 speed = 0;
	// if(speed % 10 == 0){

	// }
	// speed++;

	get_map_dimensions(g);
	if (g->ww > 5120 || g->wh > 2880)
	{
		perror("Error: Invalid map dimensions !!!. Sorry");
		return (0);
	}
	g->win = mlx_new_window(g->mlx, g->ww, g->wh, "So Long Game");
	if (!g->win)
		return (0);
	load_img(g);
	render_map(g);
	g->move = 0;
	mlx_hook(g->win, 2, 0, handle_keypress, g);
	mlx_hook(g->win, 17, 0, exit_window, g);
	mlx_loop_hook(g->mlx, loop_game, g);
	mlx_loop(g->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*pat_str;
	t_game	game;


    game.enemies = NULL;
	if (argc != 2)
	{
		perror("Your path not valid !!!. Sorry");
		return (0);
	}
	pat_str = argv[1];
	if (is_valid_map(pat_str, &game) == 0)
		return (0);
	else
	{
		is_graphic_mlx(&game);
	}
	return (0);
}
