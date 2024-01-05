/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:58:33 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/05 20:41:14 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		commands_count;
	int		input_fd;
	int		fd[2];
	char	buff[5];
	pid_t	pid;
	int		i;
	int		output_fd;
	char	**command;
	int		exit_status;
	int		here_doc;
	char	*limiter;
}			t_pipex;

void	free_2d_array(char **str);
void	check_here_doc(t_pipex *pipex, char **av, int ac);

#endif // Pipex_BONUS.h