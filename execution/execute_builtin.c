/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:31:28 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/10/26 14:11:09 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"
#include "../includes/builtins.h"

bool	is_builtin(char *cmd)
{
	bool	ret;

	ret = false;
	if (!ft_strncmp(cmd, "cd", ft_strlen(cmd)))
		ret = true;
	else if (!ft_strncmp(cmd, "echo", ft_strlen(cmd)))
		ret = true;
	else if (!ft_strncmp(cmd, "env", ft_strlen(cmd)))
		ret = true;
	else if (!ft_strncmp(cmd, "exit", ft_strlen(cmd)))
		ret = true;
	else if (!ft_strncmp(cmd, "export", ft_strlen(cmd)))
		ret = true;
	else if (!ft_strncmp(cmd, "pwd", ft_strlen(cmd)))
		ret = true;
	else if (!ft_strncmp(cmd, "unset", ft_strlen(cmd)))
		ret = true;
	return (ret);
}

int	exec_builtin(t_cmdl *cmd, t_data *data, t_env *env, int *pos)
{
	int	ret;
	int	org_io[2];

	ret = -1;
	org_io[0] = safe_dup(STDIN_FILENO);
	org_io[1] = safe_dup(STDOUT_FILENO);
	handle_pio(data->pipes, *pos, data->cmds_nbr);
	handle_rio(cmd->redir);
	if (!ft_strncmp(cmd->cmd, "cd", ft_strlen(cmd->cmd)))
		ret = builtin_cd(cmd->args);
	else if (!ft_strncmp(cmd->cmd, "echo", ft_strlen(cmd->cmd)))
		ret = builtin_echo(cmd->args);
	else if (!ft_strncmp(cmd->cmd, "env", ft_strlen(cmd->cmd)))
		ret = builtin_env(&env);
	else if (!ft_strncmp(cmd->cmd, "exit", ft_strlen(cmd->cmd)))
		ret = builtin_exit(cmd->args);
	else if (!ft_strncmp(cmd->cmd, "export", ft_strlen(cmd->cmd)))
		ret = builtin_export(cmd->args, env);
	else if (!ft_strncmp(cmd->cmd, "pwd", ft_strlen(cmd->cmd)))
		ret = builtin_pwd(cmd->args);
	else if (!ft_strncmp(cmd->cmd, "unset", ft_strlen(cmd->cmd)))
		ret = builtin_unset(cmd->args, &env);
	safe_dup2_close(org_io[0], STDIN_FILENO);
	safe_dup2_close(org_io[1], STDOUT_FILENO);
	return (ret);
}
