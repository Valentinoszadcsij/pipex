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

int	main(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid[2];
	int		status;

	if (argc != 5)
		return (ft_putstr_fd("Error: wrong number of arguments", 2),
			EXIT_FAILURE);
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		error_file(argv[1], 2);
	fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] < 0)
		return (error_file(argv[4], 2), EXIT_FAILURE);
	procs(fd, argv, pid);
	close(fd[0]);
	close(fd[1]);
	if (pid[0] > 0)
		waitpid(pid[0], &status, 0);
	if (pid[1] > 0)
		waitpid(pid[1], &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

// int main (int argc, char *argv[])
// {
// 	func(argc, argv);
// 	system("leaks pipex");
// }