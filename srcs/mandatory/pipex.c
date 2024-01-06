/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:58:16 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/05 20:55:43 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_and_exit(char *path, char **command)
{
	free(path);
	free_2d_array(command);
	exit(1);
}

char	**get_command(char *arg)
{
	char	**command;
	char	*path;

	command = ft_split(arg, ' ');
	if (access(command[0], R_OK) != -1)
		return (command);
	path = ft_strjoin("/bin/", command[0]);
	if (access(path, R_OK) != -1)
	{
		free(command[0]);
		command[0] = path;
		return (command);
	}
	free(path);
	path = ft_strjoin("/usr/bin/", command[0]);
	if (access(path, R_OK) != -1)
	{
		free(command[0]);
		command[0] = path;
		return (command);
	}
	free_and_exit(path, command);
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

void	ft_pipex(t_pipex *pipex, char **av)
{
	while (pipex->i < pipex->commands_count)
	{
		if (pipe(pipex->fd) == -1)
			exit(3);
		pipex->command = get_command(av[pipex->i + 2]);
		pipex->pid = fork();
		if (pipex->pid == -1)
			exit(4);
		if (pipex->pid == 0)
		{
			change_output(pipex);
			close(pipex->fd[0]);
			close(pipex->fd[1]);
			execve(pipex->command[0], pipex->command, NULL);
			exit(1);
		}
		waitpid(pipex->pid, &pipex->exit_status, 0);
		dup2(pipex->fd[0], 0);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		free_2d_array(pipex->command);
		pipex->i++;
	}
	close(pipex->input_fd);
	close(pipex->output_fd);
}

int	main(int ac, char **av)
{
	t_pipex	pipex;

	if (ac == 5)
	{
		pipex.commands_count = ac - 3;
		pipex.input_fd = open(av[1], O_RDONLY, 0777);
		if (pipex.input_fd < 0)
			exit(1);
		pipex.output_fd = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (pipex.output_fd < 0)
			exit(1);
		if (dup2(pipex.input_fd, 0) == -1)
			exit(2);
		pipex.i = 0;
		ft_pipex(&pipex, av);
	}
	return (0);
}
