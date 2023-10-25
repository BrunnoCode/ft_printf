/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:27:36 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/25 12:27:12 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(long int n, char x, int base, int *error)
{
	char	*sx;
	char	*bx;
	int		count;

	sx = "0123456789abcdef";
	bx = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		n = (unsigned int)n;
		count += n;
	}
	if (n < base)
	{
		if (x == 'x')
			count += ft_print_char(sx[n], error);
		else if (x == 'X')
			count += ft_print_char(bx[n], error);
		return (-1);
	}
	else
		count += ft_puthex(n / base, x, base, error);
	count += ft_puthex(n % base, x, base, error);
	return (count);
}
/*
int	main(void)
{
	printf("original: %x \n %X", -48325654, 48325654);
	puts("\n\n");
	ft_puthex(-48325654, 'x', 16);
	puts("\n\n");
	ft_puthex(48325654, 'X', 16);
	return (0);
}*/
