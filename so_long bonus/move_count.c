/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:56:51 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/11 13:08:05 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	size_number(int num)
{
	int	i;

	i = 0;
	if (num < 0)
		num *= -1;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void	handle_negative(long *n, int *i, char *string)
{
	if (*n < 0)
	{
		string[*i] = '-';
		*n *= -1;
		(*i)++;
	}
}

static char	*ft_itoa(int num)
{
	char		*string;
	int			i;
	int			count;
	long int	n;

	n = num;
	i = 0;
	count = size_number(n);
	if (n < 0 || count == 0)
		count++;
	string = (char *)malloc(count + 1);
	if (!string)
		return (NULL);
	handle_negative(&n, &i, string);
	while (count > i)
	{
		string[count - 1] = (n % 10) + '0';
		n /= 10;
		count--;
	}
	return (string);
}

void	display_move_count(t_game *g)
{
	char	*count_str;

	count_str = ft_itoa(g->move);
	mlx_clear_window(g->mlx, g->win);
	render_map(g);
	mlx_string_put(g->mlx, g->win, 10, 10, 0x000000, "Moves: ");
	mlx_string_put(g->mlx, g->win, 80, 10, 0x000000, count_str);
	free(count_str);
}
