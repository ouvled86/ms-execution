/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:46:46 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/09/30 00:03:38 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdbool.h>
# include <stdio.h>
# include <sys/stat.h>
# include <unistd.h>
# include "libft.h"
# include "execution.h"

// builtin functions
int		builtin_echo(char **args);
int		builtin_cd(char **args);
int		builtin_pwd(char **args);
int		builtin_export(char **args, t_env *env);
int		builtin_unset(char **args, t_env **env);
int		builtin_env(t_env **env);
int		builtin_exit(char **args);

// builtin utils functions
t_env	*create_enode(char *var, char *val);
t_env	*last_enode(t_env **env);
t_env	*find_var(char *var, t_env *env);
bool	find_eq(char *arg);
bool	check_var(char *var);
void	print_all_env(t_env *env);

char	*extract_var(char *arg);
char	*extract_val(char *arg);

#endif