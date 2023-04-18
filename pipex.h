/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:57:32 by voszadcs          #+#    #+#             */
/*   Updated: 2023/04/08 16:57:32 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include "lib/ft_printf/ft_printf.h"
# include "lib/libft/libft.h"

extern char	**environ;

char	*path_join(char const *s1, char const *s2);
char	**check_cmd(char *cmd);
char	**ft_split_with_q(char const *s, char *pos1, char *pos2);
int		procs(int *fd, char **argv, pid_t *pid);
void	error_file(char *s, int fd);
void	error_cmd(char *s, int fd);
void	dalloc(char **str);

#endif