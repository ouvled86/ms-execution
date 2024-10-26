/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:01:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/10/26 15:37:26 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

t_env	*initialize_env(char **env)
{
	t_env	*envl;
	t_env	*ret;
	t_env	*tmp;
	int		i;
	int		c;

	envl = NULL;
	ret = NULL;
	i = -1;
	c = -1;
	while (env[++c])
		;
	while (++i < c)
	{
		tmp = create_enode(extract_var(env[i]), extract_val(env[i]));
		if (!ret)
			ret = tmp;
		else
			envl->next = tmp;
		envl = tmp;
	}
	envl->next = NULL;
	return (ret);
}

void	print_all_env(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		printf("%s=%s\n", temp->env_var, temp->env_value);
		temp = temp->next;
	}
}

int	builtin_env(t_env **env)
{
	t_env	*temp;

	temp = *env;
	while (temp)
	{
		if (temp->env_value[0])
			printf("%s=%s\n", temp->env_var, temp->env_value);
		temp = temp->next;
	}
	return (0);
}
// int main(int ac, char **av, char **env)
// {
// 	t_env	**env_list;

// 	env_list = initialize_env(env);
// 	builtin_export(av, *env_list);
// 	print_all_env(*env_list);
// 	printf("\n\n");
// 	builtin_env(env_list);
// }
