/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:06:53 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/24 12:09:48 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *text, ...);
int	ft_atoi_base(char *str, char *base);
int	ft_atoi(const char *str);
int	ft_puthexa(unsigned long int x, int maj, int *len);
int	ft_puthexa_void(unsigned long long int x);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb, int *len);
int	ft_putunbr(unsigned int nbr, int *len);
int	ft_putpoint(void *str);

#endif
