/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:39:07 by aconta            #+#    #+#             */
/*   Updated: 2023/07/02 19:19:55 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_solo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	pthread_mutex_lock(philo->right_fork);
	log_message(philo, "has taken a fork");
	pthread_mutex_unlock(philo->right_fork);
	usleep(philo->time_to_die);
	return (NULL);
}

void	ph_thread_norme(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	log_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	log_message(philo, "has taken a fork");
	philo_eat(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		usleep(10);
	while (1)
	{
		ph_thread_norme(philo);
		pthread_mutex_lock(philo->access_mutex);
		philo->num_eat_count++;
		pthread_mutex_unlock(philo->access_mutex);
		philo_sleep(philo);
		philo_think(philo);
		pthread_mutex_lock(philo->access_mutex);
		if (--philo->num_eat_goal == 0 || philo->death_flag == 1)
		{
			pthread_mutex_unlock(philo->access_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(philo->access_mutex);
	}
	return (NULL);
}

void	create_philo_threads(pthread_t *threads, t_philo *philos)
{
	int	i;

	i = 0;
	if (philos[0].num_philo == 1)
		pthread_create(&threads[i], NULL, philo_solo_thread, &philos[i]);
	else
	{
		while (i < philos[0].num_philo)
		{
			pthread_create(&threads[i], NULL, philo_thread, &philos[i]);
			i++;
		}
	}
}

void	wait_for_philo_threads(pthread_t *threads, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo) 
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
