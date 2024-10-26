/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:20:34 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/09/26 00:39:38 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void	safe_close(int fd)
{
	if (close(fd) < 0)
	{
		perror("close");
		exit(30);
	}
}

int	safe_dup(int oldfd)
{
	int	ret;

	ret = dup(oldfd) < 0;
	if (ret < 0)
	{
		perror("dup");
		exit(49);
	}
	return (ret);
}

void	safe_dup2(int newfd, int oldfd)
{
	if (dup2(newfd, oldfd) < 0)
	{
		perror("dup2");
		exit(50);
	}
}

void	safe_dup2_close(int newfd, int oldfd)
{
	safe_dup2(newfd, oldfd);
	safe_close(newfd);
}
