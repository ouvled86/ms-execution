/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:41:50 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/09/26 00:16:55 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	p[BUFFER_SIZE + 1];
	char		*l;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX
		|| BUFFER_SIZE > INT_MAX)
		return (NULL);
	l = ft_sj(NULL, p);
	if (!l)
		return (NULL);
	if (ch_nl(p))
		return (l);
	i = 1;
	while (i > 0)
	{
		i = read(fd, p, BUFFER_SIZE);
		if (i == -1 || (i == 0 && l[0] == '\0'))
			return (free(l), NULL);
		l = ft_sj(l, p);
		if (!l)
			return (NULL);
		if (ch_nl(p))
			return (l);
	}
	return (l);
}
