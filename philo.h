/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:23:55 by aconta            #+#    #+#             */
/*   Updated: 2023/06/12 10:23:55 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
    int id;
    pthread_t thread;
    pthread_mutex_t left_fork;
    pthread_mutex_t right_fork;
} t_philo;

typedef struct s_args
{
    int number_of_philosophers;
    long int time_to_die;
    long int time_to_eat;
    long int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
} t_args;


long int	ft_long_atoi(char *str);
int check_args_num(int argc);
int check_int_limits(char **argv);
int check_only_numbers(char **argv);

# endif