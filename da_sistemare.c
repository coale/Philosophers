/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   da_sistemare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:13:47 by aconta            #+#    #+#             */
/*   Updated: 2023/06/22 09:31:28 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void grab_forks(DiningTable* table, int philo_id) 
{
    int right_fork;
    int left_fork;
    
    right_fork = philo_id;
    left_fork = (philo_id + 1) % table->number_of_philosophers;
    if (philo_id % 2 == 0) 
    {
        pthread_mutex_lock(&table->forks[right_fork]);
        pthread_mutex_lock(&table->forks[left_fork]);
    } 
    else 
    {
        pthread_mutex_lock(&table->forks[left_fork]);
        pthread_mutex_lock(&table->forks[right_fork]);
    }
}

void release_forks(DiningTable* table, int philo_id)
{
    int right_fork;
    int left_fork;
    
    right_fork = philo_id;
    left_fork = (philo_id + 1) % table->number_of_philosophers;
    pthread_mutex_unlock(&table->forks[right_fork]);
    pthread_mutex_unlock(&table->forks[left_fork]);
}

void print_state(const char* state, int philo_id)
{
    struct timeval tv;
    long long timestamp;

    gettimeofday(&tv, NULL);
    timestamp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    printf("%lld %d %s\n", timestamp, philo_id, state);
}

void destroy_table(DiningTable* table)
{
    int i = 0;
    while (i < table->number_of_philosophers) 
    {
        pthread_mutex_destroy(&table->forks[i]);
        i++;
    }
    free(table->forks);
    free(table->philosophers);
    free(table->philosopher_numbers);
    free(table->eat_count);
}
