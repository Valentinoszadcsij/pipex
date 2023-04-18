/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:21:39 by voszadcs          #+#    #+#             */
/*   Updated: 2023/04/18 21:28:59 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_split_command(char *cmd)
{
	char	*pos1;
	char	*pos2;

	pos1 = ft_strchr(cmd, '\'');
	if (!pos1)
		pos1 = ft_strchr(cmd, '"');
	if (pos1 != NULL)
	{
		pos2 = ft_strrchr(pos1, *pos1);
		if (pos2 != NULL && pos1 != pos2)
			return (ft_split_with_q(cmd, pos1, pos2));
		else
			return (ft_split(cmd, ' '));
	}
	else
		return (ft_split(cmd, ' '));
	return (NULL);
}

char	**check_with_slash(char **cmd)
{
	if (access(cmd[0], F_OK) == 0)
		return (cmd);
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	return (NULL);
}

static char	**env_true(char *env_path, char **cmd)
{
	int		i;
	char	**split_path;
	char	*full_path;
	char	*temp;

	i = 0;
	split_path = ft_split(env_path + 5, ':');
	while (split_path[i] != NULL)
	{
		full_path = path_join(split_path[i], cmd[0]);
		if (access(full_path, F_OK) == 0)
		{	
			free(cmd[0]);
			cmd[0] = full_path;
			return (cmd);
		}
		free(full_path);
		i++;
	}
	error_cmd(cmd[0], 2);
	return (NULL);
}

static char	**env_false(char **cmd)
{
	char	*full_path;

	full_path = path_join("/bin", cmd[0]);
	if (access(full_path, F_OK) == 0)
	{	
		cmd[0] = full_path;
		return (cmd);
	}
	free(full_path);
	full_path = path_join("/usr/bin", cmd[0]);
	if (access(full_path, F_OK) == 0)
	{	
		cmd[0] = full_path;
		return (cmd);
	}
	error_cmd(cmd[0], 2);
	return (NULL);
}

char	**check_cmd(char *cmd)
{
	int		i;
	char	*env_path;
	char	**split_cmd;

	i = 0;
	split_cmd = ft_split_command(cmd);
	if (ft_strchr(split_cmd[0], '/'))
		return (check_with_slash(split_cmd));
	while (environ[i] != NULL)
	{
		env_path = ft_strnstr(environ[i], "PATH=", 5);
		if (env_path)
			break ;
		else
			i++;
	}
	if (environ[i] != NULL)
		return (split_cmd = env_true(env_path, split_cmd));
	else
		return (split_cmd = env_false(split_cmd));
	return (NULL);
}
