#include "../includes/fdf.h"

int	check_arguments(int *argc, char **argv, int *fd)
{
	if (*argc != 2) // Check ouverture de plusieurs fichier ou pas de fichier
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putendl(" <filename>");
		exit(1);
	}
	if ((*fd = open(argv[1], O_RDONLY)) == -1) // Check ouverture d'un fichier inexistant
	{
		perror("Error ");
		exit(1);
	}
	return (EXIT_SUCCESS);
}
