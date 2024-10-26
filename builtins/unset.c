/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 23:03:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/09/10 23:01:30 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

static void	remove_node(char *arg, t_env **env)
{
	t_env	*temp1;
	t_env	*temp2;
	t_env	*rem_temp;

	temp1 = *env;
	temp2 = NULL;
	rem_temp = NULL;
	while (temp1 && ft_strncmp(arg, temp1->next->env_var, ft_strlen(arg)))
		temp1 = temp1->next;
	printf("%s\n", temp1->next->env_var);
	rem_temp = temp1->next;
	temp2 = rem_temp->next;
	temp1->next = temp2;
	free(rem_temp);
}

int	builtin_unset(char **args, t_env **env)
{
	t_env	*temp;
	int		i;

	temp = *env;
	i = 0;
	if (!args[i])
	{
		printf("unset: not enough argument\n");
		return (1);
	}
	while (args[i])
	{
		while (temp)
		{
			if (!ft_strncmp(temp->env_var, args[i], ft_strlen(temp->env_value)))
				remove_node(args[i], env);
			temp = temp->next;
		}
		i++;
	}
	return (0);
}

// int main(int ac, char **av, char **env)
// {
// 	t_env	**env_list;

// 	env_list = initialize_env(env);
// 	printf("%d\n\n", builtin_export(av, *env_list));
// 	// print_all_env(*env_list);
// 	printf("%d\n\n", builtin_unset(&av[1], env_list));
// 	print_all_env(*env_list);
// 	printf("\n\n");
// 	// builtin_env(env_list);
// }