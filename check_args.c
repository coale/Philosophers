

#include "philo.h"

int check_args_num(int argc)
{
    if (argc > 6 || argc < 5)
    {
        write(2, "Wrong number of arguments\n", 26);
        return (-1);
    }
    return (0);
}

int check_int_limits(char **argv)
{
    while (argv[i])
    {
        if (ft_long_atoi(argv[i]) > 2147483647 || ft_long_atoi(argv[i] < -2147483648)
        {
            write(2, "At least one of the arguments exceeds int limits\n", 49);
            return (-1);
        }
        i++;
    }
    return (0);
}

int check_only_numbers(char **argv)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (argv[i])
    {
        while (argv[i][j])
        {
            if (argv[i][j] < "0" || argv[i][j] > "9")
            {
                write(2, "Arguments can be only numbers\n", 30);
                return (-1);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

