/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:49:28 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/25 16:01:03 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long ft_power(int base, int exponente)
{
	int i = 0;
	int resultado = 1;
	while(i < exponente)
	{
		resultado *= base;
		i++;		
	}
	return (resultado);
}
int ft_putnhex(unsigned long n, char *base, int nbase)
{
		 
}



int	ft_print_char(int c)
{	
	return(write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		write(1, str, 1);
		++i;
		++str;
	}
	return (i);
}

int	ft_process(char format, va_list ptr)
{
	int	count;

	count = 0;
	if (format == '%')
		count = ft_print_str("%");
	else if (format == 'c')
		count = ft_print_char(va_arg(ptr, int));
	else if (format == 's')
		count = ft_print_str(va_arg(ptr, char *));
	// else if (format == 'd' || format == 'i')
	// 	count = ft_digit(va_arg(ptr, int));
	// else if (format == 'x' || format == 'X')
	// 	count = ft_puthex(va_arg(ptr, long int), format, 16);
	// else if(format == 'p')
	// 	count = ft_pointer(va_arg(ptr, unsigned long), 16);
	if(count == -1)
		return (-1);
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	ptr;
	int		res;
	int		i;
	int		aux;

	i = 0;
	res = 0;
	aux = 0;
	va_start(ptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			aux = res;
			res += ft_process(format[i], ptr);
			if (aux > res)
				return (-1);
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
		}
		i++;
	}
	va_end(ptr);
	return (res);
}
