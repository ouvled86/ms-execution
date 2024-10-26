/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:13:25 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/26 13:11:02 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	skip_str(char const *s, int *i, int f, int c)
{
	if (f == 0)
	{
		while (s[*i] && s[*i] != c)
			(*i)++;
	}
	else if (f == 1)
	{
		(*i)++;
		while (s[*i] && s[*i] != 39)
			(*i)++;
		(*i)++;
	}
	else if (f == 2)
	{
		(*i)++;
		while (s[*i] && s[*i] != 34)
			(*i)++;
		(*i)++;
	}
}

int	str_count(char const *s, int c)
{
	int	ret;
	int	i;
	int	f;

	ret = 0;
	i = 0;
	f = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			ret++;
			if (s[i] == 39)
				f = 1;
			else if (s[i] == 34)
				f = 2;
		}
		skip_str(s, &i, f, c);
		f = 0;
	}
	return (ret);
}

void	return_len(char const *s, int *i, int *j, int c)
{
	static int	f;

	if ((f == 1 || f == 2) && *i != 0)
	{
		(*i)++;
		f = 0;
	}
	while (s[*i] && s[*i] == c && f == 0)
		(*i)++;
	if (s[*i] == 39)
	{
		c = 39;
		(*i)++;
		f = 1;
	}
	else if (s[*i] == 34)
	{
		c = 34;
		(*i)++;
		f = 2;
	}
	*j = *i;
	while (s[*j] && s[*j] != c)
		(*j)++;
}

void	extract_strings(char **ret, char const *s, int c, int s_count)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (--s_count >= 0)
	{
		return_len(s, &i, &j, c);
		ret[k] = ft_substr(s, i, j - i);
		if (!ret[k])
		{
			ret = freemem(ret);
			exit (9);
		}
		i = j;
		k++;
	}
}

char	**new_split(char const *s, int c)
{
	char	**ret;
	int		s_count;

	s_count = str_count(s, c);
	ret = (char **)malloc((s_count + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[s_count] = NULL;
	extract_strings(ret, s, c, s_count);
	return (ret);
}
