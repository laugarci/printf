/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:03:17 by laugarci          #+#    #+#             */
/*   Updated: 2022/11/03 10:49:05 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
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

void	ft_min_or_may(unsigned int num, const char f)
{
	if (f == 'x')
		ft_putchar(num - 10 + 97);
	if (f == 'X')
		ft_putchar(num - 10 + 65);
}

int	ft_hexnum(unsigned int num, const char f)
{
	int	len;

	len = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num >= 16)
	{
		ft_hexnum(num / 16, f);
		ft_hexnum(num % 16, f);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + 48);
		else
			ft_min_or_may(num, f);
	}
	len = ft_hexnum_len(num);
	return (len);
}
