/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:44:55 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/10/26 16:32:17 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

char	**extract_paths(char *s)
{
	char	*paths;
	char	**ret;

	paths = ft_substr(s, 5, ft_strlen(s));
	if (!paths)
		exit(9);
	ret = ft_split(paths, ':');
	if (!ret)
		exit(9);
	free (paths);
	return (ret);
}

char	*find_path(char **pl, char *cmd)
{
	int		i;
	char	*full_cmd;

	i = -1;
	if ((cmd[0] == '.' && cmd[1] == '/') || cmd[0] == '/')
	{
		if (access(cmd, X_OK) < 0)
			return (NULL);
		return (cmd);
	}
	else
	{
		while (pl[++i])
		{
			full_cmd = ft_strjoin(pl[i], cmd);
			if (access(full_cmd, X_OK) == 0)
				return (full_cmd);
			free(full_cmd);
			full_cmd = NULL;
		}
	}
	return (NULL);
}

int	wait_for_childs(pid_t *pids, int cmds_nbr)
{
	int	i;
	int	status;
	int	last_exit;

	i = 0;
	status = 0;
	last_exit = -1;
	while (i < cmds_nbr)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) && last_exit <= 0)
			last_exit = WEXITSTATUS(status);
		else if (WIFSIGNALED(status) && last_exit <= 0)
			last_exit = WTERMSIG(status);
		i++;
	}
	return (last_exit);
}
