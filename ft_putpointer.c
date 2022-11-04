/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:49:51 by laugarci          #+#    #+#             */
/*   Updated: 2022/11/04 14:19:18 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_putpointer(unsigned long long n)
{
	if (n >= 16)
	{
		ft_putpointer(n / 16);
		ft_putpointer(n % 16);
	}
	else
	{
		if (n <= 9)
			if (ft_putchar(n + 48) < 0)
				return (-1);
		if (n > 9)
			if (ft_putchar(n - 10 + 97) < 0)
				return (-1);
	}
	return (1);
}

int	ft_printpointer(unsigned long long ptr)
{
	int	len;
	int	aux;

	len = 0;
	len += write(1, "0x", 2);
	aux = len;
	if (aux < 0)
		return (-1);
	if (ptr == 0)
	{
		len += write(1, "0", 1);
		aux = len;
		if (aux < 0)
			return (-1);
	}
	else
	{
		ft_putpointer(ptr);
		len += ft_ptr_len(ptr);
	}
	return (len);
}
