/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:46:32 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/25 12:28:46 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long n, int base, int *error)
{
	int	r;

	r = 0;
	r += ft_print_str("0x", error) + ft_puthex(n, 0, base, error);
	return (r);
}
