/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:35:03 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/21 17:03:53 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char f)
{
	int	putformats;

	if (f == '%')
		putformats += ft_percent();
	else if (f == 'c') //imprime caracter
		putformats += ft_putchar(va_arg(args, int));
	else if (f == 's') //imprime string
		putformats += ft_printstr(va_arg(args, char *));
/*	else if (f == 'p') //El puntero void * dado como arg se imprime en formato hexadecimal
		putformats = */
/*	else if (f == 'd') //imprime un numero decimal (base 10)
		putformats = ft_putnbr(va_arg(args, int));*/
/*	else if (f == 'i') //imprime un entero en base 10
		putformats = ft_putnbr(va_arg(args, int)); */
/*	else if (f == 'u') //imprime un numero decimal (base 10) sin signo
		putformats = */
/*	else if (f == 'x') //imprime un numero hexadecimal (base 16) en minusculas
		putformats =
	else if (f == 'X') //imprime un numero hexadecimal (base 16) en mayusculas
		putformats = */
	return (putformats);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int	i;
	int	f;

	i = 0;
	va_start (args, str);
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
	return(f);
}

