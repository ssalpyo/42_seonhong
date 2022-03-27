#include <unistd.h>

void	ft_inter(char *s1, char *s2)
{
	char asci[256];
	int i;

	i = 0;
	while (i < 256)
		asci[i++] = 0;
	i = 0;
	while (s1[i])
	{
		if (asci[(int)s1[i]] == 0)
			asci[(int)s1[i]] = 1;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (asci[(int)s2[i]] == 1)
		{
			asci[(int)s2[i]] = 0;
			write(1, &s2[i], 1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
