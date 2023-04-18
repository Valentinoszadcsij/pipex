/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_with_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 03:24:38 by voszadcs          #+#    #+#             */
/*   Updated: 2023/04/18 16:38:34 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count(char *s, char *pos1, char *pos2)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' && s[i + 1] != ' '
			&& ((s + i) < pos1 || (s + i) > pos2))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_allocate_word(char *s, char c)
{
	char	*word;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	word = malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (k < i)
	{
		word[k] = s[k];
		k++;
	}
	word[k] = '\0';
	return (word);
}

static void	*ft_free(char **arr, int i)
{
	while (i > 0)
	{
		free(arr[i - 1]);
		i--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split_with_q(char const *s, char *pos1, char *pos2)
{
	char	**arr;
	int		i;
	int		k;
	int		len;

	len = count((char *)s, pos1, pos2);
	i = -1;
	k = 0;
	arr = malloc((len + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (++i < len)
	{
		while (s[k] == ' ')
			k++;
		if (((s + k) < pos1 || (s + k) > pos2))
			arr[i] = ft_allocate_word((char *)s + k, ' ');
		else
			arr[i] = ft_allocate_word(((char *)s + k + 1), *pos1);
		if (!arr[i])
			return (ft_free(arr, i));
		k = k + (ft_strlen(arr[i]));
	}
	arr[i] = NULL;
	return (arr);
}
