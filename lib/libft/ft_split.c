/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:16:56 by voszadcs          #+#    #+#             */
/*   Updated: 2022/11/15 05:23:54 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && i == 0)
		{
			count++;
			i++;
		}
		else if (s[i] == c)
		{
			i++;
			if (s[i] != c && s[i] != '\0')
			{
				i++;
				count++;
			}
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

void	*ft_free(char **arr, int i)
{
	while (i > 0)
	{
		free(arr[i - 1]);
		i--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		k;
	int		len;

	if (!s)
		return (NULL);
	len = count((char *)s, c);
	i = -1;
	k = 0;
	arr = malloc((len + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (++i < len)
	{
		while (s[k] == c)
			k++;
		arr[i] = ft_allocate_word((char *)s + k, c);
		if (!arr[i])
			return (ft_free(arr, i));
		while (s[k] != c && s[k] != '\0')
			k++;
	}
	arr[i] = NULL;
	return (arr);
}
