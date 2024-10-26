/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:01:28 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/09/21 01:47:24 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

int	builtin_pwd(char **args)
{
	char	*pwd;

	if (args[1] != NULL)
	{
		printf("pwd: too many arguments\n");
		return (1);
	}
	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}

// int main (int ac, char **av)
// {
// 	int ret = ft_pwd(&av[1]);
// 	printf("%d\n", ret);
// }