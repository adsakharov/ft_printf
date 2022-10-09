/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:34:29 by arupert           #+#    #+#             */
/*   Updated: 2022/01/04 17:56:45 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	char	sign;
	char	hash;
	char	space;
}				t_flags;

typedef struct s_params
{
	t_flags	flags;
	char	specifier;
	char	appointed;	
}				t_params;

int		ft_putchar(char c);
int		ft_putstr(char *s);
char	ft_findchr(const char *s, char c);
int		putnbr_hex(unsigned int number, int alt, t_params params);
int		putnbr_adress(unsigned long number, t_params params);
int		putnbr_unsigned(unsigned int number);
int		putnbr_int(int number, t_params params);
int		ft_printf(const char *format, ...);

#endif