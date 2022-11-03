/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:49:51 by laugarci          #+#    #+#             */
/*   Updated: 2022/11/03 10:49:35 by laugarci         ###   ########.fr       */
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

void	ft_putpointer(unsigned long long n)
{
	if (n >= 16)
	{
		ft_putpointer(n / 16);
		ft_putpointer(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + 48);
		else
			ft_putchar(n - 10 + 97);
	}
}

int	ft_printpointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_putpointer(ptr);
		len += ft_ptr_len(ptr);
	}
	return (len);
}
