/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:44:45 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/23 22:20:40 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_digit(int n, int base)
{
	// char	*sx;
	int count;

	// sx = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		count += ft_print_char('-');
		return (ft_digit(-n, base) + 1);
	}
	/*else if (n < base)
	{
		return (ft_print_char(sx[n]));
	}*/
	else
		count += ft_digit(n / base, base);
	return (count + ft_digit(n % base, base));
}