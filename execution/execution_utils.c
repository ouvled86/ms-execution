/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 23:43:33 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/10/28 21:52:52 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

pid_t	*fork_n(int cmds_nbr)
{
	pid_t	*pids;
	int		i;

	i = 0;
	pids = (pid_t *)malloc(cmds_nbr * sizeof(pid_t));
	if (!pids)
	{
		perror("malloc");
		return (NULL);
	}
	while (i < cmds_nbr)
	{
		pids[i] = 2;
		i++;
	}
	i = 0;
	while (i < cmds_nbr)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			perror("fork");
		else if (!pids[i])
			return (pids);
		i++;
	}
	return (pids);
}

char	**ft_ltoa(t_env *env)
{
	int		i;
	int		size;
	t_env	*temp;
	char	**ret;

	i = 0;
	size = list_size(env);
	temp = env;
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
	{
		perror("malloc");
		return (NULL);
	}
	while (i < size)
	{
		ret[i] = ft_strdup(temp->full_form);
		temp = temp->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int	list_size(t_env *env)
{
	t_env	*temp;
	int		size;

	temp = env;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

bool	is_parent(pid_t *pids, int cmds_nbr)
{
	int	i;

	i = 0;
	while (i < cmds_nbr)
	{
		if (pids[i] == 0)
			return (false);
	}
	return (true);
}

char	*find_bin(char *cmd, char **env)
{
	int		i;
	char	*ret;
	char	**path_list;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	path_list = extract_paths(env[i]);
	ret = find_path(path_list, cmd);
	path_list = freemem(path_list);
	if (!ret)
		printf("cmd not found!\n");
	free(cmd);
	return (ret);
}
