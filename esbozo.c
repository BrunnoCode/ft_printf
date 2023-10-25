/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esbozo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:20:14 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/25 22:25:39 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		dataprinted;
	int		error;

	dataprinted = 0;
	error = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			error = dataprinted;
			dataprinted += ft_formats(format, ap);
			if (error > dataprinted)
				return (-1);
			else
			{
				if (write(1, format, 1) == -1)
					return (-1);
			}
			format++;
		}
	}
	va_end(ap);
	return (dataprinted);
}
