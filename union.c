#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	no_double(char *doubles, char c)
{
	int	i;

	i = 0;
	while (doubles[i] != '\0')
	{
		if (c == doubles[i])
			return (0);
		i++;
	}
	return (1);
}

void	function(char *s1, char *s2, int len)
{
	char	doubles[len];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		doubles[i] = '\0';
		i++;
	}
	i = 0;
	doubles[j] = s1[i];
	write(1, &doubles[j], 1);
	i++;
	while (s1[i] != '\0')
	{
		if (no_double(doubles, s1[i]))
		{
			j++;
			doubles[j] = s1[i];
			write(1, &doubles[j], 1);
		}
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		if (no_double(doubles, s2[i]))
		{
			j++;
			doubles[j] = s2[i];
			write(1, &doubles[j], 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	len;

	len = ft_strlen(argv[1]) + ft_strlen(argv[2]);
	if (argc == 3)
		function(argv[1], argv[2], len);
	write(1, &"\n", 1);
	return (0);
}