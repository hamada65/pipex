/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:58:33 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/08 10:17:42 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "get_next_line_bonus.h"
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
char	**ft_split_command(char *arg);
void	free_everything(char **tmp, char *command, char *tmp2, char *path);
void	check_here_doc(t_pipex *pipex, char **av, int ac);
void	ft_close_fd(int fd1, int fd2);

#endif // Pipex_BONUS.h