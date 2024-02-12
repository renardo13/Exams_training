#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_substr(char *s, char sep)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && s[i] != sep)
		str[i++] = s[i];
	str[j] = '\0';
	return (str);
}

int	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	else
		return (0);
}

int	ft_count_words(char *s, char sep)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], sep) == 1)
			i++;
		if (s[i])
			counter++;
		while (s[i] && is_sep(s[i], sep) == 0)
			i++;
	}
	return (counter);
}

char	**ft_split(char *str, char sep)
{
	char	**tab;
	int		word;
	int		i;
	int		j;

	if (!sep || !str)
		return (NULL);
	word = ft_count_words(str, sep);
	tab = malloc(sizeof(char *) * (word + 1));
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], sep))
			i++;
		if (str[i])
			tab[j++] = ft_substr(&str[i], sep);
		while (str[i] && !is_sep(str[i], sep))
			i++;
	}
	tab[word] = NULL;
	return (tab);
}

void	rev_wstr(char **tab, int word)
{
	int	i;

	word -= 1;
	while (word >= 0)
	{
		i = 0;
		while (tab[word][i])
		{
			write(1, &tab[word][i], 1);
			i++;
		}
		if (word != 0)
			write(1, " ", 1);
		word--;
	}
}

int	main(int ac, char **av)
{
	char	**tab;
	int		i;

	if (ac == 2)
	{
		i = 0;
		tab = ft_split(av[1], ' ');
		if (!tab)
			return (0);
		rev_wstr(tab, ft_count_words(av[1], ' '));
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	write(1, "\n", 1);
	return (0);
}
