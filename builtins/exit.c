/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:25:18 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/09/10 23:01:12 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

int	builtin_exit(char **args)
{
	char	*ret_string;
	int		ret_value;
	int		i;

	ret_string = args[0];
	ret_value = 0;
	i = 0;
	if (!ret_string)
		return (0);
	while (ret_string[i])
	{
		if (!ft_isdigit_signed(ret_string[i]))
		{
			printf("exit\nexit: %s: numeric argument required\n", ret_string);
			return (255); // quit program!
		}
		i++;
	}
	if (args[1])
	{
		printf("exit\nexit: too many arguments\n");
		return (1);
	}
	ret_value = ft_atoi(ret_string) % 256;
	return (ret_value);
}

// int main(int ac, char **av)
// {
// 	return(builtin_exit(&av[1]));
// }