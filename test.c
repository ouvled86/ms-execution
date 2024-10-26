#include "includes/execution.h"

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	t_cmdl	*cmdl;
	t_cmdl	*cmdl2;
	t_env	*envl;

	data = (t_data *)malloc(sizeof(t_data));
	cmdl = (t_cmdl *)malloc(sizeof(t_cmdl));
	cmdl2 = (t_cmdl *)malloc(sizeof(t_cmdl));
	envl = initialize_env(env);
	data->envl = envl;
	data->cmds_nbr = 2;
	data->pids = NULL;
	data->pipes = NULL;
	cmdl2->next = NULL;
	cmdl2->cmd = ft_strdup("wc");
	cmdl2->ldlm = NULL;
	cmdl2->args = (char **)malloc(sizeof(char *) * 2);
	cmdl2->args[0] = ft_strdup("cat");
	cmdl2->args[1] = NULL;
	cmdl->next = cmdl2;
	cmdl->cmd = ft_strdup("ls");
	cmdl->ldlm = ft_strdup("|");
	cmdl->args = (char **)malloc(sizeof(char *) * 3);
	cmdl->args[0] = ft_strdup("ls");
	cmdl->args[1] = ft_strdup("-la");
	cmdl->args[2] = NULL;
	cmdl->redir = NULL;
	data->cmd_list = cmdl;
	exec_list(data);
}
