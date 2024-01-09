/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:58:16 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/08 10:18:27 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_envp(char *envp, char **command)
{
	char	**tmp;
	char	*path;
	char	*tmp2;
	int		i;

	i = 0;
	tmp = ft_split(envp, ':');
	while (tmp[i])
	{
		tmp2 = ft_strjoin("/", command[0]);
		path = ft_strjoin(tmp[i], tmp2);
		if (access(path, R_OK) != -1)
		{
			free_everything(tmp, command[0], tmp2, NULL);
			command[0] = path;
			return (1);
		}
		free_everything(NULL, NULL, tmp2, path);
		i++;
	}
	free_everything(tmp, NULL, NULL, NULL);
	return (0);
}

char	**get_command(char *arg, char **envp)
{
	char	**command;

	command = ft_split_command(arg);
	if (access(command[0], R_OK) != -1)
		return (command);
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			if (check_envp(*envp, command))
				return (command);
			break ;
		}
		envp++;
	}
	return (command);
}

void	change_output(t_pipex *pipex)
{
	if ((pipex->i + 1) == pipex->commands_count)
	{
		if (dup2(pipex->output_fd, 1) == -1)
			exit(2);
	}
	else
	{
		if (dup2(pipex->fd[1], 1) == -1)
			exit(2);
	}
}

void	ft_pipex(t_pipex *pipex, char **av, char **envp)
{
	while (pipex->i < pipex->commands_count)
	{
		if (pipe(pipex->fd) == -1)
			exit(3);
		if (pipex->here_doc)
			pipex->command = get_command(av[pipex->i + 3], envp);
		else
			pipex->command = get_command(av[pipex->i + 2], envp);
		pipex->pid = fork();
		if (pipex->pid == -1)
			exit(4);
		if (pipex->pid == 0)
		{
			change_output(pipex);
			ft_close_fd(pipex->fd[0], pipex->fd[1]);
			execve(pipex->command[0], pipex->command, NULL);
			exit(1);
		}
		waitpid(pipex->pid, &pipex->exit_status, 0);
		dup2(pipex->fd[0], 0);
		ft_close_fd(pipex->fd[0], pipex->fd[1]);
		free_2d_array(pipex->command);
		pipex->i++;
	}
	ft_close_fd(pipex->input_fd, pipex->output_fd);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac >= 5)
	{
		check_here_doc(&pipex, av, ac);
		pipex.output_fd = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (pipex.output_fd < 0)
			exit(1);
		if (dup2(pipex.input_fd, 0) == -1)
			exit(2);
		pipex.i = 0;
		ft_pipex(&pipex, av, envp);
	}
	return (0);
}
