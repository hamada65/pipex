/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:45:49 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/06 18:00:16 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*next_line;
	static t_lst	*lst[FD_MAX];
	size_t			index;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	make_list(lst, fd);
	if (!lst[fd])
		return (NULL);
	next_line = assemble_line(lst[fd]);
	index = 0;
	del_nodes(lst, index, fd);
	return (next_line);
}

char	*assemble_line(t_lst *lst)
{
	char	*line;
	int		len;
	int		i;
	int		j;

	len = line_len(lst);
	if (!len)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	i = 0;
	while (lst)
	{
		j = 0;
		while (lst->buff[j])
		{
			line[i++] = lst->buff[j++];
			if (lst->buff[j - 1] == '\n')
				return (line);
		}
		lst = lst->next;
	}
	return (line);
}

size_t	line_len(t_lst *lst)
{
	size_t	len;
	size_t	i;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->buff[i])
		{
			len++;
			if (lst->buff[i] == '\n')
				return (len);
			i++;
		}
		lst = lst->next;
	}
	return (len);
}

void	make_list(t_lst **lst, int fd)
{
	char	*buff;
	ssize_t	num_read;

	while (!search_line(lst[fd]))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return ;
		num_read = read(fd, buff, BUFFER_SIZE);
		if (num_read <= 0)
		{
			free(buff);
			return ;
		}
		buff[num_read] = '\0';
		add_node(lst, buff, fd);
	}
}

void	add_node(t_lst **lst, char *buff, int fd)
{
	t_lst	*new_node;
	t_lst	*last_node;

	last_node = ft_listlast(lst[fd]);
	new_node = malloc((sizeof(t_lst)));
	if (!new_node)
		return ;
	if (!last_node)
		lst[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->buff = buff;
	new_node->next = NULL;
}

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("hamada", O_RDONLY);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// while(1);
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// }
