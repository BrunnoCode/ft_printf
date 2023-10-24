/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:44:45 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/24 17:04:05 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_digit(int nb)
{
	if (nb == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (nb < 0)
	{
		ft_print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_digit(nb / 10);
	ft_print_char(nb % 10 + '0');
	return (nb);
}
/*
int	main(void)
{
	printf("resultado: %d\n",	(int)ft_digit(-4566));
	printf("%d \n", 0x2A);
	return (0);
}*/
