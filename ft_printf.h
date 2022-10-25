/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:31:08 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/25 12:26:42 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
int		ft_formats(va_list args, char f);
int		ft_putchar(int c);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_putnbr(int n);
int		ft_percent(void);
int		ft_hexnum(unsigned int num, int f);

#endif
