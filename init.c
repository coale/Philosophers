/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:59:27 by aconta            #+#    #+#             */
/*   Updated: 2023/07/02 17:42:30 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_for_norme(t_philo *philos, t_mutexes *mut, int i)
{
	philos[i].num_philo = philos[0].num_philo;
	philos[i].time_to_die = philos->time_to_die;
	philos[i].time_to_eat = philos->time_to_eat;
	philos[i].time_to_sleep = philos->time_to_sleep;
	philos[i].num_eat_goal = philos->num_eat_goal;
	philos[i].num_eat_count = 0;
	philos[i].log_mutex = &mut->log_mutex;
	philos[i].death_flag = 0;
	philos[i].last_meal_time = get_timestamp(&philos[i]);
}

void	init_philo(t_philo *philos, t_mutexes *mut, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo) 
	{
		philos[i].access_mutex = &mut->access_mutex;
		philos[i].start_time = get_timestamp(&philos[i]);
		philos[i].id = i + 1;
		if (i % 2) 
		{
			philos[i].left_fork = &mut->forks[i];
			philos[i].right_fork = &mut->forks[(i + 1) % philos->num_philo];
		}
		else 
		{
			philos[i].left_fork = &mut->forks[(i + 1) % philos->num_philo];
			philos[i].right_fork = &mut->forks[i];
		}
		init_for_norme(philos, mut, i);
		i++;
	}
}
