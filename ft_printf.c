/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:35:03 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/20 18:09:02 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, char f)
{
	if (f == '%')
		write(1, "%", 1);
	else if (f == 'c') //imprime caracter
		ft_putchar(f);	
	else if (f == 's') //imprime string
		ft_putstr(f)		
	else if (f == 'p') //El puntero void * dado como arg se imprime en formato hexadecimal

	else if (f == 'd') //imprime un numero decimal (base 10)

	else if (f == 'i') //imprime un entero en base 10

	else if (f == 'u') //imprime un numero decimal (base 10) sin signo

	else if (f == 'x') //imprime un numero hexadecimal (base 16) en minusculas

	else if (f == 'X') //imprime un numero hexadecimal (base 16) en mayusculas

}


int	ft_printf(char const *str, ...)
{
	va_list	args;
	int	i;
	int	f;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			f = (ft_formats(args, str[i + 1]))
			i++;	
		}
	}
	return(0);
}
