/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:40:15 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/10/28 23:40:47 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int	handle_rout(char *file)
{
	int	out_fd;

	out_fd = -1;
	if (*file)
	{
		out_fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0666);
		if (out_fd < 0)
			perror("open");
	}
	return (out_fd);
}

int	handle_rin(char *file)
{
	int	in_fd;

	in_fd = -1;
	if (*file)
	{
		in_fd = open(file, O_RDONLY, 0666);
		if (in_fd < 0)
			perror("open");
	}
	return (in_fd);
}

int	handle_routa(char *file)
{
	int	out_fd;

	out_fd = -1;
	if (*file)
	{
		out_fd = open(file, O_CREAT | O_APPEND | O_RDWR, 0666);
		if (out_fd < 0)
			perror("open");
	}
	return (out_fd);
}

int	handle_rhdoc(char *eof_str)
{
	char	*buff;
	int		hd_pipe[2];

	buff = get_next_line(STDIN_FILENO);
	if (pipe(hd_pipe) < 0)
	{
		perror("pipe");
		return (-1);
	}
	while (buff && !ft_strncmp(buff, eof_str, ft_strlen(buff)))
	{
		if (write(hd_pipe[1], buff, ft_strlen(buff)) < 0)
			perror("write");
		buff = get_next_line(STDIN_FILENO);
	}
	if (close (hd_pipe[1]) < 0)
		perror("close");
	return (hd_pipe[0]);
}

void	handle_rio(t_redir *redirs)
{
	t_redir	*temp;
	int		in_fd;
	int		out_fd;

	temp = redirs;
	in_fd = -1;
	out_fd = -1;
	while (temp)
	{
		if (!ft_strncmp(temp->redirection, ">", 2))
			out_fd = handle_rout(temp->direction);
		else if (!ft_strncmp(temp->redirection, "<", 2))
			in_fd = handle_rin(temp->direction);
		else if (!ft_strncmp(temp->redirection, ">>", 3))
			out_fd = handle_routa(temp->direction);
		else if (!ft_strncmp(temp->redirection, "<<", 3))
			in_fd = handle_rhdoc(temp->direction);
		if (in_fd > 0)
			safe_dup2_close(in_fd, STDIN_FILENO);
		if (out_fd > 0)
			safe_dup2_close(out_fd, STDOUT_FILENO);
		temp = temp->next;
	}
}
