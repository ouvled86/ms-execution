/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:36:36 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/04 17:45:40 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*b1;
	unsigned char	*b2;

	if (!dst && !src)
		return (NULL);
	b1 = (unsigned char *) dst;
	b2 = (unsigned char *) src;
	if (b1 < b2)
		ft_memcpy(b1, b2, len);
	else
	{
		while (len > 0)
		{
			b1[len - 1] = b2[len - 1];
			len--;
		}
	}
	return (dst);
}
