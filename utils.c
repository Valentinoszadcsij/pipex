/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:56:55 by voszadcs          #+#    #+#             */
/*   Updated: 2023/04/18 21:12:56 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_join(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		size1;
	int		size2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	i = 0;
	str = malloc(size1 + size2 + 2);
	if (!str)
		return (NULL);
	while (*s1 != 0)
	{
		str[i++] = *(char *)s1++;
		if (i == size1)
			str[i++] = '/';
	}
	while (*s2 != 0)
	{
		str[i++] = *(char *)s2++;
	}
	str[i] = '\0';
	return (str);
}

void	error_file(char *s, int fd)
{
	ft_putstr_fd("pipex: ", fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	error_cmd(char *s, int fd)
{
	ft_putstr_fd("pipex: ", fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(": command not found\n", 2);
}

void	dalloc(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != NULL)
	{	
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}
