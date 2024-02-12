#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int	ft_atoi_base(const char *str, int str_base)
{
	int	nb;
	int	sign;
	int	i;
	char	*base;
	char	*base_upper;

	base = "0123456789";
	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		nb = nb * str_base + (base[str[i] - 48] - 48);
		i++;
	}
	return (nb * sign);
}
int main (int ac, char **av)
{
	if (ac == 3)
	{
		printf("%d\n", ft_atoi_base(av[1], atoi(av[2])));
	}
	return (0);
}