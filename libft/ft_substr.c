/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:37:35 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/04 17:45:40 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	sub_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	sub_len = s_len - start;
	if (start >= s_len)
		return (ft_strdup(""));
	if (sub_len > len)
		sub_len = len;
	ptr = (char *)malloc((sub_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < sub_len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr_eq(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	sub_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	sub_len = s_len - start;
	if (start >= s_len)
		return (ft_strdup(""));
	if (sub_len > len)
		sub_len = len;
	ptr = (char *)malloc((sub_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < sub_len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}