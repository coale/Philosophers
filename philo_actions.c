/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:13:47 by aconta            #+#    #+#             */
/*   Updated: 2023/07/02 18:03:49 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	useconds_t	time;
	useconds_t	time_to_eat;

	log_message(philo, "is eating");
	time = get_timestamp(philo);
	pthread_mutex_lock(philo->access_mutex);
	philo->last_meal_time = time;
	time_to_eat = philo->time_to_eat * 1000; 
	pthread_mutex_unlock(philo->access_mutex);
	usleep(time_to_eat);
}

void	philo_sleep(t_philo *philo)
{
	useconds_t	time;

	pthread_mutex_lock(philo->access_mutex);
	time = philo->time_to_sleep * 1000;
	pthread_mutex_unlock(philo->access_mutex);
	log_message(philo, "is sleeping");
	usleep(time);
}

void	philo_think(t_philo *philo)
{
	log_message(philo, "is thinking");
	usleep(1000);
}
