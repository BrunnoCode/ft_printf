/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:41:05 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/23 22:49:33 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_process(char const *format, int i, va_list ptr)
{
	if (format[i + 1] == '%')
		return (ft_print_char('%'));
	else if (format[i + 1] == 'c')
		return (ft_print_char(va_arg(ptr, int)));
	else if (format[i + 1] == 's')
		return (ft_print_str(va_arg(ptr, char *)));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (ft_digit(va_arg(ptr, int), 10));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
		return (ft_puthex(va_arg(ptr, long int), format[i + 1], 16));
	//else if (format[i + 1] == 'p')
	//	return (ft_ptr(va_arg(ptr, unsigned long)));
	return (0);
}