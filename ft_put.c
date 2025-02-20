/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:22:11 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/24 12:10:07 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		len ++;
		i ++;
	}
	return (len);
}

int	ft_putnbr(int nb, int *len)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		nbr = -nb;
		if (ft_putchar('-') == -1)
			return (-1);
		(*len)++;
	}
	else
		nbr = nb;
	if (nbr >= 10)
	{
		if (ft_putnbr(nbr / 10, len) == -1 || ft_putnbr(nbr % 10, len) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(nbr + '0') == -1)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	ft_putunbr(unsigned int nbr, int *len)
{
	if (nbr >= 10)
	{
		if (ft_putunbr(nbr / 10, len) == -1 || ft_putunbr(nbr % 10, len) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(nbr + '0') == -1)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	ft_putpoint(void *str)
{
	unsigned long long int	temp;
	int						size;
	int						len;

	len = 0;
	temp = (unsigned long long int )str;
	size = ft_putstr("0x");
	if (size == -1)
		return (-1);
	len += size;
	size = ft_puthexa_void(temp);
	if (size == -1)
		return (-1);
	len += size;
	return (len);
}
