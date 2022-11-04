/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:31:01 by laugarci          #+#    #+#             */
/*   Updated: 2022/11/04 14:20:47 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_unsigned(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_unsigned_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_putunsigned(unsigned int n)
{
	int		len;
	char	*num;
	int		aux;

	len = 0;
	if (n == 0)
	{
		len += write(1, "0", 1);
		aux = len;
		if (aux < 0)
			return (-1);
	}
	else
	{
		num = ft_unsigned(n);
		if (!num)
			return (-1);
		len += ft_printstr(num);
		free(num);
	}
	return (len);
}
