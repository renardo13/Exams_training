#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	unsigned char bit;
	int i;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + 48;
		write(1, &bit, 1);
	}
}

// unsigned char	swap_bits(unsigned char octet)
// {
// 	return ((octet >> 4) | (octet << 4));
// }

// unsigned char	reverse_bits(unsigned char octet)
// {
// 	int				j;
// 	unsigned char	ret;

// 	j = 0;
// 	while (j < 8)         
// 		ret = ret << 1 | (octet >> j++ & 1);
// 	return (ret);
// }

int	main(void)
{
	print_bits(5);
	return (0);
}