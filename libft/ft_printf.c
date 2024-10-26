/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:07:54 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/04 17:45:40 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_convert(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putuint(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa((unsigned long)va_arg(args, unsigned int), c));
	else if (c == 'X')
		return (ft_puthexa((unsigned long)va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_pointer(va_arg(args, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		tmp;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format && format[i])
	{
		tmp = count;
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (count);
			count += ft_convert(args, format[i + 1]);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		if (tmp == count + 1)
			return (va_end(args), -1);
		i++;
	}
	return (va_end(args), count);
}
