

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_fork
{
    t_fork right;
    t_fork left;
} t_fork;

typedef struct s_philo
{
    int id;
    t_fork fork;
} t_philo;

typedef struct s_args
{
    int number_of_philosophers;
    uint64_t time_to_die;
    uint64_t time_to_eat;
    uint64_t time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
} t_args;