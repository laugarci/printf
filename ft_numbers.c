/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:03:17 by laugarci          #+#    #+#             */
/*   Updated: 2022/11/04 14:04:28 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	if (!num)
		return (-1);
	len = ft_printstr(num);
	free(num);
	if (len < 0)
		return (-1);
	return (len);
}

int	ft_hexnum_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_min_or_may(unsigned int num, const char f)
{
	if (f == 'x')
	{
		if (ft_putchar(num - 10 + 97) < 0)
			return (-1);
	}
	if (f == 'X')
	{
		if (ft_putchar(num - 10 + 65) < 0)
			return (-1);
	}
	return (0);
}

int	ft_hexnum(unsigned int num, const char f)
{
	int	len;

	len = 0;
	if (num == 0)
		return (ft_putchar('0'));
	if (num >= 16)
	{
		if (ft_hexnum(num / 16, f) < 0)
			return (-1);
		if (ft_hexnum(num % 16, f) < 0)
			return (-1);
	}
	else
	{
		if (num <= 9)
			if (ft_putchar(num + 48) < 0)
				return (-1);
		if (num >= 10)
			if (ft_min_or_may(num, f) < 0)
				return (-1);
	}
	len = ft_hexnum_len(num);
	return (len);
}
