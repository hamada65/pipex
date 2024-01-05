/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:22:20 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/05 20:41:08 by mel-rhay         ###   ########.fr       */
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
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		pipex->here_doc = 1;
		pipex->limiter = av[1];
		pipex->commands_count = ac - 4;
	}
	else
	{
		pipex->commands_count = ac - 3;
		pipex->here_doc = 0;
	}
}