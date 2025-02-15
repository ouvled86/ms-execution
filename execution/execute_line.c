/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:21:17 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/10/28 23:09:37 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void	exec_list(t_data *data)
{
	t_cmdl	*cmd;
	t_cmdl	*tmp;
	char	**env_arr;
	int		exit;
	int		i;

	cmd = data->cmd_list;
	tmp = cmd;
	env_arr = ft_ltoa(data->envl);
	exit = -1;
	i = 0;
	data->pipes = create_pipes(data->cmds_nbr);
	data->pids = fork_n(data->cmds_nbr);
	while (i < data->cmds_nbr && cmd)
	{
		if (is_builtin(cmd->cmd) && is_parent(data->pids, data->cmds_nbr))
			cmd->exit = exec_builtin(cmd, data, data->envl, &i);
		else if (!is_builtin(cmd->cmd) && !data->pids[i])
			exec_cmd(cmd, data, env_arr, &i);
		cmd = cmd->next;
		i++;
	}
	// exit = wait_for_childs(data->pids, data->cmds_nbr);
	close_all_pipes(data->pipes, data->cmds_nbr);
}

void	exec_cmd(t_cmdl *cmd, t_data *data, char **env, int *pos)
{
	pid_t	*pids;

	pids = data->pids;
	if (pids[*pos] == 0)
	{
		cmd->cmd = find_bin(cmd->cmd, env);
		handle_pio(data->pipes, *pos, data->cmds_nbr);
		close_all_pipes(data->pipes, data->cmds_nbr);
		handle_rio(cmd->redir);
		execve(cmd->cmd, cmd->args, env);
		perror(cmd->args[0]);
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	t_cmdl	*cmdl;
	t_cmdl	*cmdl2;
	t_env	*envl;

	data = (t_data *)malloc(sizeof(t_data));
	cmdl = (t_cmdl *)malloc(sizeof(t_cmdl));
	cmdl2 = (t_cmdl *)malloc(sizeof(t_cmdl));
	envl = initialize_env(env);
	data->envl = envl;
	data->cmds_nbr = 2;
	data->pids = NULL;
	data->pipes = NULL;
	cmdl2->next = NULL;
	cmdl2->redir = (t_redir *)malloc(sizeof(t_redir));
	cmdl2->redir->direction = ft_strdup("text.txt");
	cmdl2->redir->redirection = ft_strdup(">");
	cmdl2->redir->next = NULL;
	cmdl2->cmd = ft_strdup("cat");
	cmdl2->ldlm = NULL;
	cmdl2->args = (char **)malloc(sizeof(char *) * 2);
	cmdl2->args[0] = ft_strdup("cat");
	cmdl2->args[1] = NULL;
	cmdl->next = cmdl2;
	cmdl->cmd = ft_strdup("ls");
	cmdl->ldlm = ft_strdup("|");
	cmdl->args = (char **)malloc(sizeof(char *) * 3);
	cmdl->args[0] = ft_strdup("ls");
	cmdl->args[1] = ft_strdup("-la");
	cmdl->args[2] = NULL;
	cmdl->redir = NULL;
	data->cmd_list = cmdl;
	exec_list(data);
}
