/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:56:21 by voszadcs          #+#    #+#             */
/*   Updated: 2023/04/08 16:56:21 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//check_cmd() first isolates PATH from **envp with ft_strnstr
//then we need to split that string by ':' and check if cmd1
//and cmd2 exist in any given path
//if commands dont exist return false, else true
char	**check_cmd(char *cmd, char **envp)
{
	int		i;
	char	*env_path;
	char	**split_path;
	char	*full_path;
	char	**split_cmd;
	char	*temp;

	i = 0;
	while (envp[i] != NULL)
	{
		env_path = ft_strnstr(envp[i], "PATH=", 5);
		if (env_path)
			break ;
		else
			i++;
	}
	i = 0;
	split_path = ft_split(env_path + 5, ':');
	split_cmd = ft_split(cmd, ' ');
	while (split_path[i] != NULL)
	{
		full_path = ft_strjoin(split_path[i], split_cmd[0]);
		//printf("%s\n", full_path);
		if (access(full_path, F_OK) == 0)
		{	
			temp = split_cmd[0];
			split_cmd[0] = full_path;
			return (split_cmd);
		}
		free(full_path);
		i++;
	}
	perror("Error: ");
	return (NULL);
}

int	proc1(char **envp, char **cmd, int pipe_fd[2], int input_fd)
{
	close(pipe_fd[0]);
	dup2(input_fd, 0);
	dup2(pipe_fd[1], 1);
	close(input_fd);
	close(pipe_fd[1]);
	printf("proccess 1");
	execve(cmd[0], cmd, envp);
	return (perror("Error"), EXIT_FAILURE);
}

int	proc2(char **envp, char **cmd, int pipe_fd[2], int output_fd)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	dup2(output_fd, 1);
	close(output_fd);
	close(pipe_fd[0]);
	printf("proccess 2");
	execve(cmd[0], cmd, envp);
	return (perror("Error"), EXIT_FAILURE);
}

//3rd arg to main is environment variable, which is a 2d array containing PATH variable
//PATH holds pathes where bash commands might be located, seperated by ':'
//As for pipex without bonus we only pass 5 arguments to program hence checking it
int	main(int argc, char **argv, char **envp)
{
	int		input_fd;
	int		output_fd;
	char	**cmd1_path;
	char	**cmd2_path;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (printf("Error: wrong number of arguments\n"), EXIT_FAILURE);
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		return (perror(argv[1]), EXIT_FAILURE);
	output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (output_fd == -1)
		return (perror(argv[4]), EXIT_FAILURE);
	cmd1_path = check_cmd(argv[2], envp);
	cmd2_path = check_cmd(argv[3], envp);
	if (pipe(pipe_fd) == -1)
		return (perror("Error"), EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("Error"), EXIT_FAILURE);
	if (pid1 == 0)
		proc1(envp, cmd1_path, pipe_fd, input_fd);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Error"), EXIT_FAILURE);
	if (pid2 == 0)
		proc2(envp, cmd2_path, pipe_fd, output_fd);
	close(input_fd);
	close(output_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}
