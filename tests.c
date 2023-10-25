/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:30:35 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/25 15:46:54 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// ft_printf("mi funcion: %%\n");
	// ft_printf("mi funcion: %x %d %i \n", -455, 455, -455);
	printf("%ld", ft_power(2, 3));

	return (0);
}