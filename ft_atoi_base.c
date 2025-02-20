/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:10:23 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/18 14:24:48 by pchapuis         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size ++;
	return (size);
}

int	ft_put_base(char *base, int size, char *str, int n)
{	
	int	result;
	int	i;
	int	j;
	int	x;

	i = 0;
	result = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != base[j])
		{
			j ++;
			if (j > size)
				return (result);
		}
		x = i ;
		while (n - x++ > 1)
		{
			j *= size;
		}
		result = result + j;
		i ++;
	}
	return (result);
}

int	ft_end(char *str, int start, char *base, int size)
{
	int	end;
	int	j;

	end = start;
	while (str[end])
	{
		j = 0;
		while (str[end] != base[j])
		{
			j ++;
			if (j > size)
				return (end);
		}
		end ++;
	}
	return (end);
}

int	ft_atoi(char *base, int size, char *str)
{
	int	i;
	int	sign;
	int	start;
	int	end;

	i = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i ++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i ++;
	}
	start = i;
	end = ft_end(str, start, base, size) - start;
	return (ft_put_base(base, size, str + start, end) * sign);
}

int	ft_atoi_base(char *str, char *base)
{	
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == '-' || base[i] == '+'
				|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
				return (0);
			j ++;
		}
		i ++;
	}
	if (i <= 1 || base[i - 1] == '-' || base[i - 1] == '+'
		|| base[i - 1] == ' ' || (base[i - 1] >= 9 && base[i - 1] <= 13))
		return (0);
	return (ft_atoi(base, ft_strlen(base), str));
}
