/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:21:39 by voszadcs          #+#    #+#             */
/*   Updated: 2023/04/15 20:06:46 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_with_q(char *cmd, char *pos1, char *pos2)
{
	printf("Hello %s || %s\n", pos1, pos2);
	return (ft_split(cmd, ' '));
}

char	**ft_split_command(char *cmd)
{
	char	*pos1;
	char	*pos2;

	pos1 = ft_strchr(cmd, '\'');
	if (pos1 != NULL)
	{
		pos2 = ft_strrchr(pos1, '\'');
		if (pos2 != NULL && pos1 != pos2)
			return (split_with_q(cmd, pos1, pos2));
		else
			return (ft_split(cmd, ' '));
	}
	else
		return (ft_split(cmd, ' '));
	return (NULL);
}
