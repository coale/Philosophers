
#include "philo.h"

int	check_args(int argc, char **argv)
{
	if ((argc < 5 || argc > 6) || ft_long_atoi(argv[1]) < 1 || ft_long_atoi(argv[2]) < 0 \
				|| ft_long_atoi(argv[3]) < 0 || ft_long_atoi(argv[4]) < 0 \
				|| ft_long_atoi(argv[1]) > 2147483647 || ft_long_atoi(argv[2]) > 2147483647 \
				|| ft_long_atoi(argv[3]) > 2147483647 || ft_long_atoi(argv[4]) > 2147483647) 
	{
		printf("Invalid arguments.\n");
		return (1);
	}
	if (argc == 6)
	{
		if (ft_long_atoi(argv[5]) > 2147483647)
		{
			printf("Invalid arguments.\n");
			return (1);
		}
	}
	return (0);
}