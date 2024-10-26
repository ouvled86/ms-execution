/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:08:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/04 17:45:40 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	max_size;
	char	*jstr;

	if (!s1 || !s2)
	{
		if (s1)
			return (ft_strdup(s1));
		if (s2)
			return (ft_strdup(s2));
		if (!s1 && !s2)
			return (NULL);
	}
	max_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	jstr = malloc(max_size * sizeof(char));
	if (!jstr)
		return (NULL);
	i = 0;
	while (*s1)
		jstr[i++] = *s1++;
	while (*s2)
		jstr[i++] = *s2++;
	jstr[i] = '\0';
	return (jstr);
}
