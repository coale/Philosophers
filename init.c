/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:59:27 by aconta            #+#    #+#             */
/*   Updated: 2023/06/21 09:59:27 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void* philosopher(void* arg)
{
    PhilosopherData* data;
    DiningTable* table;
    int philo_id ;
    int eat_limit_reached;

    data = (PhilosopherData*)arg;
    table = data->table;
    philo_id = data->philo_id;
    eat_limit_reached = 0;
    while (1) 
    {
        grab_forks(table, philo_id);
        print_state("has taken a fork", (philo_id + 1));

        print_state("is eating", (philo_id + 1));
        usleep(table->time_to_eat * 1000);

        release_forks(table, philo_id);
        print_state("is sleeping", (philo_id + 1));
        usleep(table->time_to_sleep * 1000);

        if (table->number_of_times_each_philosopher_must_eat > 0) 
        {
            table->eat_count[philo_id]++;
            if (table->eat_count[philo_id] >= table->number_of_times_each_philosopher_must_eat)
                eat_limit_reached = 1;
        }
        if (eat_limit_reached)
            break;
    }
    return NULL;
}

void initialize_table(DiningTable* table, int argc, char* argv[])
{
    int i;

    table->number_of_philosophers = atoi(argv[1]);
    table->time_to_die = atoi(argv[2]);
    table->time_to_eat = atoi(argv[3]);
    table->time_to_sleep = atoi(argv[4]);
    table->number_of_times_each_philosopher_must_eat = -1;

    if (argc == 6)
        table->number_of_times_each_philosopher_must_eat = atoi(argv[5]);

    table->forks = malloc(table->number_of_philosophers * sizeof(pthread_mutex_t));
    table->philosophers = malloc(table->number_of_philosophers * sizeof(pthread_t));
    table->philosopher_numbers = malloc(table->number_of_philosophers * sizeof(int));
    table->eat_count = malloc(table->number_of_philosophers * sizeof(int));

    i = 0;
    while (i < table->number_of_philosophers) {
        pthread_mutex_init(&table->forks[i], NULL);
        table->philosopher_numbers[i] = i + 1;
        table->eat_count[i] = 0;
        i++;
    }
}