#include "pipex.h"

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

char	*ft_strnstr(const char *haystack, const char *needle, int n)
{
	int	i;
	int	count;

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

int	ft_strlen(const char *s)
{
	int	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0' )
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		size1;
	int		size2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	i = 0;
	str = malloc(size1 + size2 + 2);
	if (!str)
		return (NULL);
	while (*s1 != 0)
	{
		str[i++] = *(char *)s1++;
	}
    str[i++] = '/';
	while (*s2 != 0)
	{
		str[i++] = *(char *)s2++;
	}
	str[i] = '\0';
	return (str);
}