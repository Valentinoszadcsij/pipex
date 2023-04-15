/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:54:25 by voszadcs          #+#    #+#             */
/*   Updated: 2023/04/15 19:55:43 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);


#endif
