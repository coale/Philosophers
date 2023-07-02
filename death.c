/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:40:58 by aconta            #+#    #+#             */
/*   Updated: 2023/07/02 19:13:16 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo *philo)
{
	useconds_t	current_time;
	int			time_since_last_meal;

	current_time = get_timestamp(philo);
	pthread_mutex_lock(philo->access_mutex);
	time_since_last_meal = current_time - philo->last_meal_time;
	if (time_since_last_meal > philo->time_to_die)
	{
		pthread_mutex_unlock(philo->access_mutex);
		log_message(philo, "died");
		pthread_mutex_lock(philo->access_mutex);
		philo->death_flag = 1;
		pthread_mutex_unlock(philo->access_mutex);
		return ;
	}
	pthread_mutex_unlock(philo->access_mutex);
}

void	*while_death(t_philo *philo, int n_philo, int n_eat, int i)
{
	while (n_eat != 0)
	{
		while (i < n_philo)
		{
			check_death(&philo[i]);
			pthread_mutex_lock(philo->access_mutex);
			if (philo[i].death_flag == 1)
			{
				i = 0;
				while (i < n_philo)
					philo[i++].death_flag = 1;
				pthread_mutex_unlock(philo->access_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(philo->access_mutex);
			usleep(1000);
			i++;
		}
		i = 0;
		pthread_mutex_lock(philo->access_mutex);
		n_eat = philo->num_eat_goal;
		pthread_mutex_unlock(philo->access_mutex);
	}
	return (NULL);
}

void	*death_thread(void *arg)
{
	t_philo	*philo;
	int		i;
	int		n_eat;
	int		n_philo;

	philo = (t_philo *)arg;
	i = 0;
	n_eat = 1;
	pthread_mutex_lock(philo->access_mutex);
	n_philo = philo->num_philo;
	pthread_mutex_unlock(philo->access_mutex);
	while_death(philo, n_philo, n_eat, i);
	return (NULL);
}

void	start_death_threads(t_philo *philos)
{
	pthread_t	death_threads;

	pthread_create(&death_threads, NULL, death_thread, philos);
	pthread_join(death_threads, NULL);
}
