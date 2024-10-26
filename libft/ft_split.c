/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:12:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/19 12:13:48 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check(char const *str, char c)
{
	int	occurances;
	int	i;

	occurances = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			occurances++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (occurances);
}

char	**freemem(char **res)
{
	int	i;

	i = 0;
	if (res)
	{
		while (res[i])
			free(res[i++]);
		free(res);
	}
	return (NULL);
}

static char	*extract(int *i, char const *s, char c)
{
	int		ressize;
	int		tpos;
	int		j;
	char	*res;

	j = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	tpos = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	ressize = *i - tpos;
	res = (char *)malloc((ressize + 2) * sizeof(char));
	if (!res)
		return (NULL);
	while (tpos + j < *i)
	{
		res[j] = s[tpos + j];
		j++;
	}
	res[j] = '/';
	res[j + 1] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		occurances;
	char	**result;

	j = 0;
	if (!s)
		return (NULL);
	occurances = check(s, c);
	result = (char **)malloc ((occurances + 1) * sizeof (char *));
	if (!result)
		return (NULL);
	i = 0;
	while (j < occurances)
	{
		result[j] = extract(&i, s, c);
		if (result[j] == NULL)
			return (freemem(result));
		j++;
	}
	result[occurances] = NULL;
	return (result);
}
