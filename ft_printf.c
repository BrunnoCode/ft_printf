/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esbozo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:20:14 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/26 11:00:10 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchr(int c, int *datap)
{
	if(*datap != -1)
	{
		if(write(1, &c, 1) == -1)
			*datap = -1;
		else
			*datap += 1;	
	}
}
void	ft_str(char *str, int *datap)
{
	if (!str)
		ft_str("(null)", datap);
	else
		while (*str)
		{
			ft_putchr(*str, datap);
			str++;
		}
}

void	ft_number(unsigned long n, int *datap, unsigned long base, char *basestr)
{
	if(n < 0)
	{
		ft_putchr('-', datap);
		n = -n;
	}	
	if(n >= base)
		ft_number(n  / base, datap, base, basestr);
	if(*datap == -1)
		return ;
	ft_putchr(basestr[n % base], datap);
}

void	ft_formats(const char *formato, va_list ap, int *datap)
{
	if (*formato == '%')
		ft_putchr('%', datap);		
	else if (*formato == 'c')
		ft_putchr(va_arg(ap, int), datap);		
	else if (*formato == 's')
		return (ft_str(va_arg(ap, char *), datap));
	else if (*formato == 'd' || *formato == 'i')
		ft_number(va_arg(ap, int), datap, 10, "0123456789");
	else if (*formato == 'u')
		ft_number(va_arg(ap, unsigned int), datap, 10, "0123456789");
	else if (*formato == 'x')
		ft_number(va_arg(ap, unsigned int), datap, 16, "0123456789abcdef");
	else if (*formato == 'X')
		ft_number(va_arg(ap, unsigned int), datap, 16, "0123456789ABCDEF");
	else if (*formato == 'p')
	{
		ft_str("0x", datap);
		ft_number(va_arg(ap, unsigned long), datap, 16, "0123456789abcdef");
	}
}
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		dataprinted;

	dataprinted = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_formats(++format, ap, &dataprinted);
		}
		else
			ft_putchr(*format, &dataprinted);
		format++;
	}
	va_end(ap);
	return (dataprinted);
}
