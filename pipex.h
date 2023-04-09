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

char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, int n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif