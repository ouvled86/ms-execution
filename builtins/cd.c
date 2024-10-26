/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:59:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/09/25 01:55:17 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

static bool	check_path(char *path)
{
	struct stat	d_stat;

	if (stat(path, &d_stat) < -1)
	{
		perror("stat");
		exit (1);
	}
	if (d_stat.st_mode & S_IXUSR)
		return (true);
	return (false);
}

static char	*gen_path(char **args)
{
	int		i;
	char	*path;

	i = 1;
	path = NULL;
	while (args[i])
	{
		if (i != 1)
			path = ft_strjoin(path, " ");
		path = ft_strjoin(path, args[i++]);
	}
	return (path);
}

int	builtin_cd(char **args)
{
	const char	*path;
	int			e_status;

	path = gen_path(args);
	if (check_path(args[1]))
	{
		e_status = chdir(path);
		if (e_status)
		{
			perror("cd");
			return (e_status);
		}
	}
	return (0);
}

// int	main(int ac, char **av, char **env)
// {
// 	int ret = builtin_cd(av, env);
// 	char *pwd;

//     pwd = getcwd(NULL, 0);
//     printf("%s, %d", pwd, ret);
//     free(pwd);
// }
