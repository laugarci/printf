/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:35:03 by laugarci          #+#    #+#             */
/*   Updated: 2022/11/03 10:55:25 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, char f)
{
	int	res;

	res = 0;
	if (f == '%')
		res = ft_percent();
	else if (f == 'c')
		res = ft_putchar(va_arg(args, int));
	else if (f == 's')
		res = ft_printstr(va_arg(args, char *));
	else if (f == 'p')
		res += ft_printpointer(va_arg(args, unsigned long long));
	else if (f == 'd')
		res = ft_putnbr(va_arg(args, int));
	else if (f == 'i')
		res = ft_putnbr(va_arg(args, int));
	else if (f == 'u')
		res = ft_putunsigned(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		res = ft_hexnum(va_arg(args, unsigned int), f);
	return (res);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		f;

	i = 0;
	f = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			f += ft_formats(args, str[i + 1]);
			i += 2;
		}
		else
		{
			f += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (f);
}
