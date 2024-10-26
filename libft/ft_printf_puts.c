/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:08:52 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/04 17:45:40 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_puthexa(unsigned long n, int c)
{
	int		count;
	char	*base_str;
	int		tmp;

	base_str = base(c);
	count = 0;
	if (n >= 16)
	{
		tmp = count;
		count += ft_puthexa(n / 16, c);
		if (tmp == count + 1)
			return (-1);
		tmp = count;
		count += ft_puthexa(n % 16, c);
		if (tmp == count + 1)
			return (-1);
	}
	else
	{
		tmp = count;
		count += ft_putchar(base_str[n]);
		if (tmp == count + 1)
			return (-1);
	}
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	int	count;
	int	tmp;

	count = 0;
	if (n >= 10 || n < 0 || n == -2147483648)
	{
		tmp = count;
		count += reccursive(n, count, tmp);
		if (tmp == count + 1)
			return (-1);
	}
	else
	{
		tmp = count;
		count += ft_putchar (n + '0');
		if (tmp == count + 1)
			return (-1);
	}
	return (count);
}

int	ft_putuint(unsigned int n)
{
	int	count;
	int	tmp;

	count = 0;
	if (n > 9)
	{
		tmp = count;
		count += ft_putuint(n / 10);
		if (tmp == count + 1)
			return (-1);
		tmp = count;
		count += ft_putchar (n % 10 + '0');
		if (tmp == count + 1)
			return (-1);
	}
	else
	{
		tmp = count;
		count += ft_putchar(n + '0');
		if (tmp == count + 1)
			return (-1);
	}
	return (count);
}

int	ft_putstr(char *str)
{
	int	i;
	int	tmp;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		tmp = count;
		count += ft_putchar(str[i++]);
		if (tmp == count + 1)
			return (-1);
	}
	return (count);
}
