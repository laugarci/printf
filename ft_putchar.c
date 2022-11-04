/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:29:59 by laugarci          #+#    #+#             */
/*   Updated: 2022/11/04 14:03:53 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;
	int	aux;

	i = 0;
	aux = 0;
	if (str == NULL)
	{
		aux += ft_printstr("(null)");
		if (aux < 0)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (write(1, &str[i], 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_percent(void)
{
	if (write(1, "%", 1) < 0)
		return (-1);
	return (1);
}
