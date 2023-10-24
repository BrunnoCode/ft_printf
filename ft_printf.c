/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:49:28 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/23 22:29:15 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *format, ...)
{
	va_list	ptr;
	int		res;
	int		i;

	i = 0;
	res = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_my_strchr("cspdiuxX%", format[i + 1]))
		{
			res += ft_process(format, i, ptr);
			i++;
		}
		else
		{
			res += ft_print_char(format[i]);
		}
		i++;
	}
	va_end(ptr);
	return (res);
}

int	main(void)
{
	ft_printf("mi funcion: %x %d %i \n", -455, 455, -455);
	printf("Original: %x %d %i \n", -455, 455, -455);
	return (0);
}
/*
OUTPUT original:

		hola mundo
		b
		30
		42
		-42
		0x55742c399050
		1f4
		1F4
		%%
		*/
