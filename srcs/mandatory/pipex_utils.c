/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:22:20 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/07 21:54:24 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*ft_command_join(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)malloc((l1 + l2 + 1 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, l1);
	str[l1] = ' ';
	ft_memcpy((str + l1 + 1), s2, l2);
	str[l1 + l2 + 1] = '\0';
	return (str);
}

char	**ft_dup(char **tmp, int count)
{
	char	**args;
	char 	*tmp_string;
	int		i;
	int		j;

	args = (char **)malloc(sizeof(char *) * (count + 1));
	i = 0;
	j = 0;
	printf("count: %d\n", count);
	while (tmp[i])
	{
		if (ft_strchr(tmp[i], '\''))
		{
			printf("A: %s\n", tmp[i]);
			tmp_string = ft_strtrim(tmp[i], "\'");
			args[j] = tmp_string;
			j++;
			i++;
		}
		else
		{
			printf("B: %s\n", tmp[i]);
			args[j] = ft_strdup(tmp[i]);
			j++;
		}
		i++;
	}
	args[j] = NULL;
	free_2d_array(tmp);
	return (args);
}

char	**ft_split_command(char *arg)
{
	char	**tmp;
	char	*tmp_string;
	int		i;
	int		count;

	tmp = ft_split(arg, ' ');
	i = 0;
	count = 0;
	while (tmp[i])
	{
		if (tmp[i + 1] && ft_strchr(tmp[i], '\'') && ft_strchr(tmp[i + 1], '\''))
		{
			tmp_string = ft_command_join(tmp[i], tmp[i + 1]);
			free(tmp[i]);
			tmp[i] = tmp_string;
			count++;
			i++;
		}
		i++;
	}
	return (ft_dup(tmp, i - count));
}