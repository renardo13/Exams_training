#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(&s[start]))
	{
		len = ft_strlen(&s[start]);
	}
	str = malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}

void	ft_free(char **strs, int n)
{
	int	i;

	i = 0;
	if (!strs[n])
	{
		while (strs[i])
			free(strs[i++]);
		free(strs);
	}
	return ;
}

static size_t	ft_len(char const *s, char *sep)
{
	size_t	len;
	int		i;

	len = 0;
	while (s[len])
	{
		i = 0;
		while (sep[i])
		{
			if (s[len] == sep[i])
				return (len);
			i++;
		}
		len++;
	}
	return (len);
}

static int	ft_is_c(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_count_words(char const *s, char *sep)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && ft_is_c(s[i], sep) == 1)
			i++;
		if (s[i])
			counter++;
		while (s[i] && ft_is_c(s[i], sep) == 0)
			i++;
	}
	return (counter);
}

char	**ft_split(char *s, char *sep)
{
	size_t	i;
	size_t	n;
	char	**strs;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (ft_count_words(s, sep) + 1));
	if (!strs)
		return (NULL);
	while (s[i])
	{
		while (s[i] && ft_is_c(s[i], sep) == 1)
			i++;
		if (s[i] && ft_is_c(s[i], sep) == 0)
		{
			strs[n++] = ft_substr(s, i, ft_len(&s[i], sep));
			ft_free(strs, n - 1);
		}
		while (s[i] && ft_is_c(s[i], sep) == 0)
			i++;
	}
	strs[n] = NULL;
	return (strs);
}

int	main(void)
{
	int j;
	char s[] = "cyoucouyufcoucouucouf";
	char sep[] = "yufc";

	j = 0;

	char **strs = ft_split(s, sep);

	while (strs[j])
	{
		printf("%s\n", strs[j]);
		j++;
	}
}
