/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:46:30 by aconta            #+#    #+#             */
/*   Updated: 2023/07/02 18:57:35 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_norme(char **argv, t_philo *philos)
{
	philos[0].num_philo = atoi(argv[1]);
	philos->time_to_die = atoi(argv[2]);
	philos->time_to_eat = atoi(argv[3]);
	philos->time_to_sleep = atoi(argv[4]);
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
		philos = ft_calloc(atoi(argv[1]), sizeof(t_philo));
		mut.forks = create_forks(atoi(argv[1]));
		threads = malloc(atoi(argv[1]) * sizeof(pthread_t));
		assign_norme(argv, philos);
		philos->num_eat_goal = -1;
		if (argc == 6)
			philos->num_eat_goal = atoi(argv[5]);
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
