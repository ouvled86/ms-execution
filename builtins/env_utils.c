/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:46:01 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/10/26 15:24:36 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

t_env	*create_enode(char *var, char *val)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
	{
		perror("malloc");
		return (NULL);
	}
	if (var)
		new->env_var = var;
	if (val)
		new->env_value = val;
	else
		new->env_value = ft_strdup("");
	new->full_form = ft_strjoin(ft_strjoin(var, "="), val);
	return (new);
}

t_env	*last_enode(t_env **env)
{
	t_env	*temp;

	temp = *env;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_env	*find_var(char *var, t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if ((ft_strlen(var) == ft_strlen(temp->env_var))
			&& ft_strncmp(var, temp->env_var, ft_strlen(var)))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

bool	find_eq(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (true);
		i++;
	}
	return (false);
}

bool	check_var(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (!ft_isalpha(var[i]))
		{
			printf("export: not an identifier: %s\n", var); 
			return (false);
		}
		i++;
	}
	return (true);
}
