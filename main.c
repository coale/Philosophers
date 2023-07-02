/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandra <alessandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:46:30 by aconta            #+#    #+#             */
/*   Updated: 2023/07/02 23:22:14 by alessandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_norme(char **argv, t_philo *philos)
{
	philos[0].num_philo = ft_long_atoi(argv[1]);
	philos->time_to_die = ft_long_atoi(argv[2]);
	philos->time_to_eat = ft_long_atoi(argv[3]);
	philos->time_to_sleep = ft_long_atoi(argv[4]);
}

int	main(int argc, char **argv)
{
	t_philo		*philos;
	pthread_t	*threads;
	t_mutexes	mut;

	if (!check_args(argc, argv))
	{
		pthread_mutex_init(&mut.log_mutex, NULL);
		pthread_mutex_init(&mut.access_mutex, NULL);
		philos = ft_calloc(ft_long_atoi(argv[1]), sizeof(t_philo));
		mut.forks = create_forks(ft_long_atoi(argv[1]));
		threads = malloc(ft_long_atoi(argv[1]) * sizeof(pthread_t));
		assign_norme(argv, philos);
		philos->num_eat_goal = -1;
		if (argc == 6)
			philos->num_eat_goal = ft_long_atoi(argv[5]);
		init_philo(philos, &mut, philos[0].num_philo);
		create_philo_threads(threads, philos);
		start_death_threads(philos);
		wait_for_philo_threads(threads, philos->num_philo);
		destroy_forks(mut.forks, philos->num_philo);
		free(philos);
		free(threads);
		return (0);
	}
	return (1);
}
