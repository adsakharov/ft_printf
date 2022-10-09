/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:34:33 by arupert           #+#    #+#             */
/*   Updated: 2022/01/04 17:56:35 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_0x(t_params let_case, unsigned long number)
{
	int	numofprinted;

	if (number == 0)
		if (let_case.specifier == 'x' || let_case.specifier == 'X')
			return (0);
	numofprinted = ft_putchar('0');
	if (let_case.specifier == 'x' || let_case.specifier == 'p')
		numofprinted += ft_putchar('x');
	else if (let_case.specifier == 'X')
		numofprinted += ft_putchar('X');
	return (numofprinted);
}

int	putnbr_hex(unsigned int number, int alt, t_params params)
{
	const char	digits[] = "0123456789abcdef0123456789ABCDEF";
	int			arrofdigs[8];
	int			i;
	int			numofprinted;

	numofprinted = 0;
	if (params.flags.hash == 'y')
		numofprinted = write_0x(params, number);
	i = 8;
	while (i > 0)
	{
		arrofdigs[i - 1] = number % 16;
		i--;
		number /= 16;
	}
	while (arrofdigs[i] == 0 && i < 7)
		i++;
	while (i <= 7)
	{
		numofprinted += ft_putchar(digits[arrofdigs[i] + alt]);
		i++;
	}
	return (numofprinted);
}

int	putnbr_adress(unsigned long number, t_params params)
{
	const char	digits[] = "0123456789abcdef";
	int			arrofdigs[16];
	int			i;
	int			numofprinted;

	numofprinted = 0;
	i = 16;
	while (i > 0)
	{
		arrofdigs[i - 1] = number % 16;
		i--;
		number /= 16;
	}
	while (arrofdigs[i] == 0 && i < 15)
		i++;
	numofprinted += write_0x(params, number);
	while (i <= 15)
	{
		numofprinted += ft_putchar(digits[arrofdigs[i]]);
		i++;
	}
	return (numofprinted);
}
