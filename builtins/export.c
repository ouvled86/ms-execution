/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:47:26 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/09/30 00:03:21 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

char	*extract_var(char *arg)
{
	char	*ret;

	ret = NULL;
	if (arg)
	{
		if (find_eq(arg))
			ret = ft_substr(arg, 0, ft_strchrpos(arg, '='));
		else
			ret = arg;
	}
	return (ret);
}

char	*extract_val(char *arg)
{
	if (arg)
	{
		if (find_eq(arg))
			return (ft_substr(arg, ft_strchrpos(arg, '=') + 1, ft_strlen(arg)));
		else
			return (NULL);
	}
	return (NULL);
}

static bool	var_aexst(char *var, t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (var == temp->env_var)
			return (true);
		temp = temp->next;
	}
	return (false);
}

static int	export_var(t_env **env, char *var, char *val)
{
	t_env	*temp;

	temp = last_enode(env);
	if (!check_var(var))
		return (1);
	temp->next = create_enode(var, val);
	if (!temp->next)
		return (1);
	return (0);
}

int	builtin_export(char **args, t_env *env)
{
	char	*var;
	char	*val;
	t_env	*temp;

	if (!args[1])
	{
		print_all_env(env);
		return (0);
	}
	var = extract_var(args[1]);
	val = extract_val(args[1]);
	if (var_aexst(var, env) && val)
	{
		temp = find_var(var, env);
		temp->env_value = val;
		return (0);
	}
	return (export_var(&env, var, val));
}

// int main(int ac, char **av, char **env)
// {
// 	t_env	**env_list;

// 	env_list = initialize_env(env);
// 	printf("%d\n", builtin_export(av, *env_list));
// 	print_all_env(*env_list);
// }