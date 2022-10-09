/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:38:15 by arupert           #+#    #+#             */
/*   Updated: 2022/01/04 13:48:46 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_unsigned(unsigned int number)
{
	int			arrofdigs[10];
	int			i;
	int			numofprinted;

	numofprinted = 0;
	i = 10;
	while (i > 0)
	{
		arrofdigs[i - 1] = number % 10;
		i--;
		number /= 10;
	}
	while (arrofdigs[i] == 0 && i < 9)
		i++;
	while (i <= 9)
	{
		numofprinted += ft_putchar('0' + arrofdigs[i]);
		i++;
	}
	return (numofprinted);
}

int	putnbr_int(int number, t_params params)
{
	int			numofprinted;
	long int	l_number;

	numofprinted = 0;
	if (number < 0)
	{
		params.flags.sign = '-';
		l_number = -1 * (long int)(number);
	}
	else
		l_number = (long int)number;
	if (params.flags.sign != 'n')
		numofprinted += ft_putchar(params.flags.sign);
	else if (params.flags.space == 'y')
		numofprinted += ft_putchar(' ');
	numofprinted += putnbr_unsigned((unsigned int)l_number);
	return (numofprinted);
}
