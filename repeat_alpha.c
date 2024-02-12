#include <unistd.h>
#include <stdio.h>

void ft_putstr(char c, int iter)
{
	while (iter)
	{
		write (1, &c, 1);
		iter--;
	}
}

int main (int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];
		int i;

		i = 0;
		while (s[i])
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				ft_putstr(s[i], s[i] - 64);
			else if (s[i] >= 'a' && s[i] <= 'z')
				ft_putstr(s[i], s[i] - 96);
			else 
				ft_putstr(s[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}

