/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:31:08 by laugarci          #+#    #+#             */
/*   Updated: 2022/11/04 14:01:28 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		ft_formats(va_list args, char f);
int		ft_putchar(int c);
int		ft_printstr(char *str);
int		ft_putnbr(int n);
int		ft_percent(void);
int		ft_hexnum(unsigned int num, const char f);
int		ft_hexnum_len(unsigned int num);
char	*ft_itoa(int n);
int		ft_unsigned_len(unsigned int n);
char	*ft_unsigned(unsigned int n);
int		ft_putunsigned(unsigned int n);
int		ft_printpointer(unsigned long long ptr);
int		ft_ptr_len(unsigned long long n);
int		ft_putpointer(unsigned long long n);
int		ft_min_or_may(unsigned int num, const char f);
#endif
