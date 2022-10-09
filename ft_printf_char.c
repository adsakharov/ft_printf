/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:00:57 by arupert           #+#    #+#             */
/*   Updated: 2022/01/04 16:45:44 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (*(s + i) != '\0')
	{
		write(1, &(*(s + i)), 1);
		i++;
	}
	return (i);
}

char	ft_findchr(const char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == c)
			return ('y');
		i++;
	}
	return ('n');
}
