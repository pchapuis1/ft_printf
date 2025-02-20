/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:19:29 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/24 12:10:14 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_hexa(char c, int maj)
{
	int	temp;
	int	len;

	len = 0;
	if (maj == 1 && c >= 'a' && c <= 'f')
	{
		temp = c - 32;
		if (ft_putchar(temp) == -1)
			return (-1);
		len ++;
	}
	else
	{
		if (ft_putchar(c) == -1)
			return (-1);
		len ++;
	}
	return (len);
}

int	ft_puthexa(unsigned long int x, int maj, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (x >= 16)
	{
		if (ft_puthexa(x / 16, maj, len) == -1
			|| ft_puthexa(x % 16, maj, len) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar_hexa(hex[x], maj) == -1)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	ft_puthexa_void(unsigned long long int x)
{
	char	*hex;
	int		len;
	int		temp;
	int		temp1;

	len = 0;
	hex = "0123456789abcdef";
	if (x >= 16)
	{
		temp = ft_puthexa_void(x / 16);
		temp1 = ft_puthexa_void(x % 16);
		if (temp == -1 || temp1 == -1)
			return (-1);
		len += temp + temp1;
	}
	else
	{
		if (ft_putchar (hex[x]) == -1)
			return (-1);
		len ++;
	}
	return (len);
}
