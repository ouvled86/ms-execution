/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 23:03:32 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/10/26 14:14:45 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "builtins.h"
#ifndef EXECUTION_H
# define EXECUTION_H

# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

// Environment struct
typedef struct s_env
{
	char			*full_form;
	char			*env_var;
	char			*env_value;
	struct s_env	*next;
}					t_env;

// Redirection struct
typedef struct s_redir
{
	char			*redirection;
	char			*direction;
	struct s_redir	*next;
}					t_redir;

// Command line struct
typedef struct s_cmdl
{
	int				exit;
	char			**args;
	char			*cmd;
	char			*ldlm;
	t_redir			*redir;
	struct s_cmdl	*next;
}					t_cmdl;

// Data struct
typedef struct s_data
{
	t_cmdl	*cmd_list;
	t_env	*envl;
	int		**pipes;
	int		*pids;
	int		cmds_nbr;
	int		last_exit;
}			t_data;

// Functions that handle command line pipe redirections
void	handle_pio(int **pipes, int pos, int cmds_nbr);
void	close_all_pipes(int **pipes, int cmds_nbr);
int		**create_pipes(int cmds_nbr);

// Command line executon utils
int		list_size(t_env *env);
int		wait_for_childs(pid_t *pids, int cmds_nbr);
bool	is_parent(pid_t *pids, int cmds_nbr);
bool	is_builtin(char *cmd);
pid_t	*fork_n(int cmds_nbr);
char	*find_bin(char *cmd, char **env);
char	*find_path(char **pl, char *cmd);
char	**extract_paths(char *s);
char	**ft_ltoa(t_env *env);

// This function handles the redirections (<; >; <<; >>)
void	handle_rio(t_redir *redirs);

// Functions that execute a command line
void	exec_list(t_data *data);
void	exec_cmd(t_cmdl *cmd, t_data *data, char **env, int *pos);
int		exec_builtin(t_cmdl *cmd, t_data *data, t_env *env, int *pos);

// Safe functions for file management
int		safe_dup(int oldfd);
void	safe_close(int fd);
void	safe_dup2(int newfd, int oldfd);
void	safe_dup2_close(int newfd, int oldfd);

// Environment utilities
t_env	*initialize_env(char **env_org);
char	*extract_var(char *arg);
char	*extract_val(char *arg);

#endif