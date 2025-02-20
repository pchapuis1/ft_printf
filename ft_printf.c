/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:42:58 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/24 12:10:02 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(const char *text, int i, va_list parameters, int *len)
{
	int	size;

	size = 0;
	if (text[i + 1] == 'c')
		size += ft_putchar((va_arg(parameters, int)));
	else if (text[i + 1] == 's')
		size += ft_putstr((va_arg(parameters, char *)));
	else if (text[i + 1] == 'p')
		size += ft_putpoint((va_arg(parameters, void *)));
	else if (text[i + 1] == 'd' || text[i + 1] == 'i')
		size += ft_putnbr(va_arg(parameters, int), len);
	else if (text[i + 1] == 'u')
		size += ft_putunbr(va_arg(parameters, unsigned int), len);
	else if (text[i + 1] == 'x')
		size += ft_puthexa((va_arg(parameters, unsigned int)), 0, len);
	else if (text[i + 1] == 'X')
		size += ft_puthexa((va_arg(parameters, unsigned int)), 1, len);
	else if (text[i + 1] == '%')
		size += ft_putchar('%');
	else
		return (-2);
	if (size == -1)
		return (-1);
	return (size);
}

static int	ft_check(const char *text, int i, va_list parameters, int *len)
{
	int	temp;

	temp = ft_convert(text, i, parameters, len);
	if (temp == -1)
		return (-1);
	if (temp != -2)
	{
		(*len) += temp;
		i ++;
	}
	i ++;
	return (i);
}

int	ft_printf(const char *text, ...)
{
	int		i;
	va_list	parameters;
	int		len;

	va_start(parameters, text);
	i = 0;
	len = 0;
	while (text[i])
	{
		while (text[i] != '%' && text[i])
		{
			if (ft_putchar(text[i ++]) == -1)
				return (-1);
			len ++;
		}
		if (text[i] == '%' && text[i + 1])
		{
			i = ft_check(text, i, parameters, &len);
			if (i == -1)
				return (-1);
		}
	}
	va_end (parameters);
	return (len);
}
