/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:38:35 by arupert           #+#    #+#             */
/*   Updated: 2022/01/04 17:52:39 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	appoint_null(void)
{
	t_params	null_params;

	null_params.flags.sign = 'n';
	null_params.flags.hash = 'n';
	null_params.flags.space = 'n';
	null_params.specifier = '\0';
	null_params.appointed = 'n';
	return (null_params);
}

static t_params	find_flags(const char **fmt)
{
	t_params	params;
	int			i;

	params = appoint_null();
	i = 0;
	while ((params.appointed != 'y') && ((*fmt)[i] != '\0'))
	{
		i++;
		if (ft_findchr("cspdiuxX%", (*fmt)[i]) == 'y')
		{
			params.specifier = (*fmt)[i];
			params.appointed = 'y';
		}
		else if ((*fmt)[i] == '+')
			params.flags.sign = '+';
		else if ((*fmt)[i] == '#')
			params.flags.hash = 'y';
		else if ((*fmt)[i] == ' ')
			params.flags.space = 'y';
		else
			break ;
	}
	if (params.appointed == 'y')
		*fmt = *fmt + i;
	return (params);
}

static int	choose_the_way(va_list ap, t_params params)
{
	int	numofprinted;

	numofprinted = 0;
	if (params.specifier == 'c')
		numofprinted = ft_putchar(va_arg(ap, int));
	else if (params.specifier == 's')
		numofprinted = ft_putstr(va_arg(ap, char *));
	else if (params.specifier == 'p')
		numofprinted = putnbr_adress(va_arg(ap, unsigned long int), params);
	else if (params.specifier == 'd' || params.specifier == 'i')
		numofprinted = putnbr_int(va_arg(ap, int), params);
	else if (params.specifier == 'u')
		numofprinted = putnbr_unsigned(va_arg(ap, unsigned int));
	else if (params.specifier == 'x')
		numofprinted = putnbr_hex(va_arg(ap, unsigned int), 0, params);
	else if (params.specifier == 'X')
		numofprinted = putnbr_hex(va_arg(ap, unsigned int), 16, params);
	else if (params.specifier == '%')
		numofprinted = ft_putchar('%');
	return (numofprinted);
}

static int	ft_printf_inside(const char **format, va_list ap)
{
	t_params	params;
	int			numofprinted;

	numofprinted = 0;
	while (**format)
	{
		if (**format == '%' && (*format)[1] == '\0')
			return (-1);
		else if (**format == '%')
		{
			params = find_flags(format);
			if (params.appointed == 'y')
				numofprinted += choose_the_way(ap, params);
		}
		else if (!**format)
			return (numofprinted);
		else
			numofprinted += ft_putchar(**format);
		*format = *format + 1;
	}
	return (numofprinted);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			numofprinted;

	va_start(ap, format);
	numofprinted = ft_printf_inside(&format, ap);
	va_end(ap);
	return (numofprinted);
}
