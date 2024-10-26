/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:35:10 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/27 19:47:53 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	skip_spaces(const char *str, int *i, int *sign)
{
	while (str[*i] == 32 || str[*i] == '\v' || str[*i] == '\t' || 
		str[*i] == '\f' || str[*i] == '\r' || str[*i] == '\n')
		(*i)++;
	if (str[*i] == '-')
	{
		*sign *= -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
}

int	ft_atoi(const char *str)
{
	long	n;
	int		i;
	int		sign;
	long	tmp;

	n = 0;
	i = 0;
	sign = 1;
	skip_spaces(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = n * 10 + (str[i] - '0');
		if (n > tmp && sign == 1)
			return (-1);
		if (n > tmp && sign == -1)
			return (0);
		n = tmp;
		i++;
	}
	return (sign * n);
}
