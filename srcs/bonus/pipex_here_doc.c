/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:01:05 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/08 10:22:02 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_here_doc(t_pipex *pipex, char **av)
{
	int		tmp_fd;
	char	*str;
	char	*tmp;

	tmp_fd = open("here_doc", O_WRONLY | O_APPEND | O_CREAT, 0777);
	if (tmp_fd < 0)
		exit(1);
	str = get_next_line(0);
	while (str)
	{
		tmp = ft_strtrim(str, "\n");
		if (!(ft_strncmp(tmp, av[2], ft_strlen(tmp) + 1)))
		{
			free(tmp);
			free(str);
			break ;
		}
		write(tmp_fd, str, ft_strlen(str));
		free(str);
		free(tmp);
		str = get_next_line(0);
	}
	close(tmp_fd);
	pipex->input_fd = open("here_doc", O_RDONLY, 0777);
	unlink("here_doc");
}

void	check_here_doc(t_pipex *pipex, char **av, int ac)
{
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		pipex->here_doc = 1;
		pipex->limiter = av[2];
		pipex->commands_count = ac - 4;
		ft_here_doc(pipex, av);
	}
	else
	{
		pipex->input_fd = open(av[1], O_RDONLY, 0777);
		if (pipex->input_fd < 0)
			exit(1);
		pipex->commands_count = ac - 3;
		pipex->here_doc = 0;
	}
}

void	ft_close_fd(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
