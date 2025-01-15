/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:27:56 by achemlal          #+#    #+#             */
/*   Updated: 2024/11/21 11:29:34 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int nb)
{
	int	res;

	res = 0;
	if (nb > 9)
	{
		res += ft_unsigned_putnbr(nb / 10);
		res += ft_unsigned_putnbr(nb % 10);
	}
	else
		res += ft_putchar(nb + '0');
	return (res);
}
