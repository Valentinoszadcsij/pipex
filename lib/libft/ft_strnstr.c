/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:37:04 by voszadcs          #+#    #+#             */
/*   Updated: 2022/11/13 20:59:44 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!*needle || needle == haystack)
		return ((char *)haystack);
	if (n == 0)
		return (0);
	while (haystack[i] && i < n)
	{
		count = 0;
		while (haystack[count + i] == needle[count] && (count + i) < n)
		{
			count++;
			if (needle[count] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
