/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:03:17 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/25 13:37:41 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbr(n);
	}
	else if (n < 10)
	{
		c = n + 48;
		ft_putchar(n);
	}
	else
	{
		ft_putnbr(n / 10);
		c = (n % 10) + 48;
		ft_putchar(c);
	}
	return (1);
}

int	ft_hexnum(unsigned int num, int f)
{
	if (num >= 16)
	{
		ft_hexnum(num / 16, f);
		ft_hexnum(num % 16, f);
	}
	else
	{
		if (f <= 9)
			ft_putchar(num + 48);
		else
		{
			if (f == 'x')
				ft_putchar(num - 10 + 'a');
			if (f == 'X')
				ft_putchar(num - 10 + 'A');
		};	
	}
	return ();
}
