#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*shrink(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

int	compare(char *dest, char *one)
{
	int	i;

	i = ft_strlen(dest);
	dest[i] = '\0';
	i = 0;
	while (dest[i] != '\0' && one[i] != '\0')
	{
		if (dest[i] != one[i])
			return (1);
		i++;
	}
	return (0);
}

int	anagram(char *one, char *two)
{
	char	dest[ft_strlen(one) + 1];
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	if (ft_strlen(one) == ft_strlen(two))
	{
		printf("test\n");
		printf("%s\n", one);
		printf("%s\n", two);
		while (one[i] != '\0')
		{
			while (two[j] != '\0')
			{
				if (one[i] == two[j])
				memcpy(dest, (const void *)one, i);
				j++;
			}
			i++;
			j = 0;
		}
		printf("%s\n", dest);
		if (!compare(dest, one))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	argv[1] = shrink(argv[1]);
	argv[2] = shrink(argv[2]);
	if (anagram(argv[1], argv[2]))
	{
		printf("test\n");
		return (1);
	}
	return (0);
}

// memcpy: vergelijk dest met one
// geen memcpy: check of alles in two speciaal karakter is