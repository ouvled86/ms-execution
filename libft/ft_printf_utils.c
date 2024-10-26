/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:47:06 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/04 17:45:40 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	reccursive(int n, int count, int tmp)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		tmp = count;
		count += ft_putchar ('-');
		if (tmp == count + 1)
			return (-1);
		tmp = count;
		count += ft_putnbr (-n);
		if (tmp == count + 1)
			return (-1);
	}
	else if (n > 9)
	{
		tmp = count;
		count += ft_putnbr(n / 10);
		if (tmp == count + 1)
			return (-1);
		tmp = count;
		count += ft_putchar (n % 10 + '0');
		if (tmp == count + 1)
			return (-1);
	}
	return (count);
}

char	*base(int c)
{
	if (c == 'x')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

int	ft_pointer(void *p)
{
	int				count;
	unsigned long	ptr;
	int				tmp;

	if (!p)
		return (ft_putstr("0x0"));
	ptr = (unsigned long)p;
	count = ft_putstr("0x");
	if (count == -1)
		return (-1);
	tmp = count;
	count += ft_puthexa(ptr, 'x');
	if (tmp == count + 1)
		return (-1);
	return (count);
}
