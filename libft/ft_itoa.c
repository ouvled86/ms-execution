/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:30:18 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/04 17:45:40 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	counter(int n)
{
	int	count;
	int	num;

	num = n;
	count = 0;
	if (n < 0)
	{
		num = n * -1;
		count++;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	if (n == 0)
		count = 1;
	return (count);
}

static char	*conversion(int count, int n, int sign)
{
	char	*result;
	int		num;

	result = (char *)malloc((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		num = n * -1;
		result[0] = '-';
	}
	else
		num = n;
	result[count] = '\0';
	while (count > sign)
	{
		result[count - 1] = (num % 10) + 48;
		num /= 10;
		count--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				count;
	int				sign;

	sign = 0;
	if (n < 0)
		sign++;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = counter(n);
	result = conversion(count, n, sign);
	return (result);
}
