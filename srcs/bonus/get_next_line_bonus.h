/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:45:58 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/06 18:00:56 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42L
# endif

typedef struct s_lst
{
	char			*buff;
	struct s_lst	*next;
}					t_lst;

char				*get_next_line(int fd);
void				make_list(t_lst **lst, int fd);
int					search_line(t_lst *lst);
void				add_node(t_lst **lst, char *buff, int fd);
t_lst				*ft_listlast(t_lst *lst);
char				*assemble_line(t_lst *lst);
size_t				line_len(t_lst *lst);
void				del_nodes(t_lst **lst, size_t i, int fd);
int					check_node(char *s);
size_t				ft_strlen(const char *s);
void				trim_word(char *dst, const char *src, size_t size);
#endif