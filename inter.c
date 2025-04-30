#include <unistd.h>

int	main(int argc, char **argv)
{
	int	lookup[256] = {}; //ascii tabel om te markeren
	int	j;
	int i = 0;

	if (argc == 3)
	{
		while (argv[1][i]) // loop door 1e string
		{
			j = 0; // begin bij 1e letter
			while (argv[2][j]) // pas 2e string toe op 1 letter van eerste string
			{
				if (argv[1][i] == argv[2][j] && lookup[(int)argv[2][j]]) // check voor zelfde letter en check of gemarkeerd
				{
					lookup[(int)argv[2][j]] = 1;
					write(1, &argv[1][i], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, &"\n", 1);
}