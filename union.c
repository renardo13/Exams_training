#include <unistd.h>

// the principle is to go to the index of my tab determine by 
// the value of the encounter characters and put 1 or let a 0 (this technique works with others exos like inter)
int main (int ac, char **av)
{
	if (ac == 3)
	{
		int tab[255] = {0};
		char *s1 = av[1];
		char *s2 = av[2];
		int i;

		i = 0;
		while (s1[i])
		{
			if (tab[s1[i]] == 0)
			{
				write (1, &s1[i], 1);
				tab[s1[i]] = 1;
			}
			i++;
		}
		i = 0;
		while (s2[i])
		{
			if (tab[s2[i]] == 0)
			{
				write (1, &s2[i], 1);
				tab[s2[i]] = 1;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
