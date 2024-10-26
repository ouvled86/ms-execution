/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:42:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/10/26 15:38:47 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int	**create_pipes(int cmds_nbr)
{
	int	**pipes;
	int	i;

	i = 0;
	pipes = (int **)malloc((cmds_nbr - 1) * sizeof(int *));
	if (!pipes)
	{
		perror("malloc");
		return (NULL);
	}
	while (i < cmds_nbr - 1)
	{
		pipes[i] = (int *)malloc(2 * sizeof(int));
		if (!pipes[i])
		{
			perror("malloc");
			return (NULL);
		}
		if (pipe(pipes[i]) < 0)
			perror("pipe");
		i++;
	}
	return (pipes);
}

void	handle_pio(int **pipes, int pos, int cmds_nbr)
{
	int	in_fd;
	int	out_fd;

	in_fd = -1;
	out_fd = -1;
	if (pos == 0 && cmds_nbr > 1)
	{
		in_fd = -1;
		out_fd = pipes[0][1];
	}
	else if (pos == cmds_nbr - 1 && cmds_nbr > 1)
	{
		in_fd = pipes[pos - 1][0];
		out_fd = -1;
	}
	else if (pos != 0 && pos != cmds_nbr - 1 && cmds_nbr > 1)
	{
		in_fd = pipes[pos - 1][0];
		out_fd = pipes[pos][1];
	}
	if (in_fd > 0)
		safe_dup2(in_fd, STDIN_FILENO);
	if (out_fd > 0)
		safe_dup2(out_fd, STDOUT_FILENO);
}

void	close_all_pipes(int **pipes, int cmds_nbr)
{
	int	i;

	i = 0;
	while (i < cmds_nbr && cmds_nbr != 1)
	{
		safe_close(pipes[i][0]);
		safe_close(pipes[i][1]);
		free(pipes[i]);
		i++;
	}
	free(pipes);
}
