/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:25:15 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/24 00:01:55 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		ft_process(char const *format, int i, va_list ptr);
char	*ft_my_strchr(char *str, int c);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_digit(int n, int base);
int		ft_puthex(long int n, char x, int base);

#endif