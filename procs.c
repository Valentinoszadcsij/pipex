/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 07:01:12 by voszadcs          #+#    #+#             */
/*   Updated: 2023/04/22 01:09:36 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	proc1(char **cmd, int pipe_fd[2], int input_fd)
{
	close(pipe_fd[0]);
	dup2(input_fd, 0);
	dup2(pipe_fd[1], 1);
	close(input_fd);
	close(pipe_fd[1]);
	if (access(cmd[0], X_OK) != 0)
		exit (126);
	execve(cmd[0], cmd, environ);
	perror("execve: ");
	exit (EXIT_FAILURE);
}

int	proc2(char **cmd, int pipe_fd[2], int output_fd)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	dup2(output_fd, 1);
	close(output_fd);
	close(pipe_fd[0]);
	if (access(cmd[0], X_OK) != 0)
		exit (126);
	execve(cmd[0], cmd, environ);
	perror("execve: ");
	exit (EXIT_FAILURE);
}

int	procs(int *fd, char **argv, pid_t *pid)
{	
	char	**cmd1_path;
	char	**cmd2_path;
	int		pipe_fd[2];

	cmd1_path = check_cmd(argv[2]);
	cmd2_path = check_cmd(argv[3]);
	if (pipe(pipe_fd) == -1)
		return (perror("Error: "), EXIT_FAILURE);
	pid[0] = fork();
	if (pid[0] == 0 && cmd1_path != NULL && fd[0] > -1)
		proc1(cmd1_path, pipe_fd, fd[0]);
	else if (pid[0] == -1 || pid[0] == 0)
		return (EXIT_FAILURE);
	pid[1] = fork();
	if (pid[1] == 0 && cmd2_path != NULL)
		proc2(cmd2_path, pipe_fd, fd[1]);
	else if (pid[1] == -1 || pid[1] == 0)
		exit (127);
	if (cmd1_path)
		dalloc(cmd1_path);
	if (cmd2_path)
		dalloc(cmd2_path);
	return (close(pipe_fd[0]), close(pipe_fd[1]), EXIT_SUCCESS);
}
