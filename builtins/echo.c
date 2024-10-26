/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:01:09 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/09/10 22:59:51 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

static int	handle_flag(char *arg, int spf)
{
	int	i;
	int	ret;

	i = 1;
	ret = 1;
	if (arg && !ft_strncmp(arg, "-n", 2))
	{
		ret = 0;
		while (arg[i])
		{
			if (arg[i] != 'n')
			{
				if (spf == 1)
					printf("%s ", arg);
				else
					printf("%s", arg);
				return (1);
			}
			i++;
		}
	}
	return (ret);
}

int	builtin_echo(char **args)
{
	int	i;
	int	nlf;
	int	spf;

	spf = 0;
	if (args[1])
		spf = 1;
	nlf = handle_flag(args[0], spf);
	i = 1;
	if (!args)
		return (0);
	while (args[i] && args[i + 1])
	{
		printf("%s ", args[i]);
		i++;
	}
	if (args[i])
		printf("%s", args[i]);
	if (nlf)
		printf("\n");
	return (0);
}

// int main(int ac, char **av)
// {
// 	builtin_echo(&av[1]);
// 	return (0);
// }
