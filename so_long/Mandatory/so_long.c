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
void f()
{
	system ("leaks so_long");
}
static int	is_valid_map( char *pat_str, t_game *g)
{
	if (ft_strncmp(pat_str + ft_strlen(pat_str) - 4, ".ber", 4) != 0)
	{
		perror("Error : Extention (.ber). Sorry");
		return (0);
	}
	if (check_map(pat_str, g) == 0)
	{
		perror("Error : Your map not valid !!!. Sorry");
		return (0);
	}
	else
		return (1);
}

static int	is_graphic_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		exit(0);
	get_map_dimensions(g);
	if (g->ww > 5120 || g->wh > 2880)
	{
		perror("Error: Invalid map dimensions !!!. Sorry");
		return (0);
	}
	g->win = NULL;
	if (!g->win)
		exit(0);
	// load_img(g);
	// render_map(g);
	// g->move = 0;
	// mlx_hook(g->win, 2, 0, handle_keypress, g);
	// mlx_loop(g->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	atexit(f);
	char	*pat_str;
	t_game	game;

	if (argc != 2)
	{
		perror("Your path not valid !!!. Sorry");
		return (0);
	}
	pat_str = argv[1];
	if (is_valid_map(pat_str, &game) == 0)
		return (free_map(game.map), free(game.str), close(game.fd), 0);
		printf("str : %p\n", game.str);
	if (is_graphic_mlx(&game) == 0)
		return (free_map(game.map), free(game.str), close(game.fd), 0);
	return (0);
}
