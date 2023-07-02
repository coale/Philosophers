/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:43:54 by aconta            #+#    #+#             */
/*   Updated: 2023/07/02 18:48:53 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*create_forks(int num_forks)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = (pthread_mutex_t *)malloc(num_forks * sizeof(pthread_mutex_t));
	if (forks == NULL)
		exit (0);
	while (i < num_forks)
	{
		if (pthread_mutex_init(&forks[i++], NULL) != 0)
			exit (0);
	}
	return (forks);
}

void	destroy_forks(pthread_mutex_t *forks, int num_forks)
{
	int	i;

	i = 0;
	while (i < num_forks) 
		pthread_mutex_destroy(&forks[i++]);
	free(forks);
}
