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

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct {
    pthread_mutex_t* forks;
    pthread_t* philosophers;
    int* philosopher_numbers;
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
    int* eat_count;
} DiningTable;

typedef struct {
    DiningTable* table;
    int philo_id;
} PhilosopherData;


long int	ft_long_atoi(char *str);
int check_args_num(int argc);
int check_int_limits(char **argv);
int check_only_numbers(char **argv);
void* philosopher(void* arg);
void initialize_table(DiningTable* table, int argc, char* argv[]);
void destroy_table(DiningTable* table);

# endif