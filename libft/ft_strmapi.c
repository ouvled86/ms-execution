/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:28:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/04 17:45:40 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*b;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	b = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!b)
		return (NULL);
	i = 0;
	while (s[i])
	{
		b[i] = f(i, s[i]);
		i++;
	}
	b[i] = '\0';
	return (b);
}
