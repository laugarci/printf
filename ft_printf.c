/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:35:03 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/25 13:37:34 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, char f)
{
	int	res;
	
	res = 0;
	if (f == '%')
		res = ft_percent();
	else if (f == 'c') //imprime caracter
		res += ft_putchar(va_arg(args, int));
	else if (f == 's') //imprime string
		res += ft_printstr(va_arg(args, char *));
/*	else if (f == 'p') //El puntero void * dado como arg se imprime en formato hexadecimal
		res = */
	else if (f == 'd') //imprime un numero decimal (base 10)
		res += ft_putnbr(va_arg(args, int));
	else if (f == 'i') //imprime un entero en base 10
		res += ft_putnbr(va_arg(args, int));
/*	else if (f == 'u') //imprime un numero decimal (base 10) sin signo
		res = */
	else if (f == 'x' || f == 'X') //imprime un numero hexadecimal (base 16) en minusculas || mayusculas
		res += ft_hexnum(va_arg(args, unsigned int), f);
	return (res);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int	i;
	int	f;

	i = 0;
	f = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			f += ft_formats(args, str[i + 1]);
			i++;	
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
