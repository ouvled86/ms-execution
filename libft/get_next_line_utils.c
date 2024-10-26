/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:41:55 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/09/26 00:17:00 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_sl(char *s)
{
	size_t	l;

	l = 0;
	while (s && s[l] && s[l] != '\n')
		l++;
	if (s && s[l] == '\n')
		l++;
	return (l);
}

int	ch_nl(char *s)
{
	int	f;
	int	i;
	int	j;

	f = 0;
	i = 0;
	j = 0;
	while (s && s[i])
	{
		if (f == 1)
			s[j++] = s[i];
		else if (s[i] == '\n')
			f = 1;
		s[i] = '\0';
		i++;
	}
	return (f);
}

char	*ft_sj(char *l, char *p)
{
	char	*r;
	size_t	i;
	size_t	j;

	r = (char *)malloc(ft_sl(l) + ft_sl(p) + 1);
	if (!r)
		return (free(l), NULL);
	i = 0;
	j = 0;
	while (l && l[i])
	{
		r[i] = l[i];
		i++;
	}
	while (p && p[j] && p[j] != '\n')
	{
		r[i + j] = p[j];
		j++;
	}
	if (p && p[j] == '\n')
		r[i + j++] = '\n';
	r[i + j] = '\0';
	if (l)
		free(l);
	return (r);
}
