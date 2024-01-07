/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:58:33 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/07 21:37:11 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
}			t_pipex;

void	free_2d_array(char **str);
char	**ft_split_command(char *arg);
#endif // Pipex.h