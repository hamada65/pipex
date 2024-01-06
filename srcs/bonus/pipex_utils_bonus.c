/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:22:20 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/06 20:57:22 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_2d_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	check_here_doc(t_pipex *pipex, char **av, int ac)
{
	int tmp_fd;
	char *str;
	char *tmp;

	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		pipex->here_doc = 1;
		pipex->limiter = av[2];
		pipex->commands_count = ac - 4;
		tmp_fd = open("here_doc", O_WRONLY | O_APPEND | O_CREAT, 0777);
		if (tmp_fd < 0)
			exit(1);
		str = get_next_line(0);
		while (str)
		{
			tmp = ft_strtrim(str, "\n");
			if (!(ft_strncmp(tmp, av[2], ft_strlen(tmp))))
			{
				free(tmp);
				free(str);
				break;
			}
			write(tmp_fd, str, ft_strlen(str));
			free(str);
			free(tmp);
			str = get_next_line(0);
		}
		close(tmp_fd);
		pipex->input_fd = open("here_doc", O_RDONLY, 0777);;
		unlink("here_doc");
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