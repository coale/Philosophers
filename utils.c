/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:40:14 by aconta            #+#    #+#             */
/*   Updated: 2023/07/02 18:11:30 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ps;

	i = 0;
	ps = (char *)s;
	while (i < n)
	{
		ps[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	arr = malloc(nmemb * size);
	if (!arr)
		return (0);
	ft_bzero(arr, size * nmemb);
	return (arr);
}

int	check_args(int argc, char **argv)
{
	if ((argc < 5 || argc > 6) || atoi(argv[1]) < 1 || atoi(argv[2]) < 0 \
				|| atoi(argv[3]) < 0 || atoi(argv[4]) < 0 \
				|| atoi(argv[1]) > 2147483647 || atoi(argv[2]) > 2147483647 \
				|| atoi(argv[3]) > 2147483647 || atoi(argv[4]) > 2147483647) 
	{
		printf("Invalid arguments.\n");
		return (1);
	}
	if (argc == 6)
	{
		if (atoi(argv[5]) > 2147483647)
		{
			printf("Invalid arguments.\n");
			return (1);
		}
	}
	return (0);
}

useconds_t	get_timestamp(t_philo *philo)
{
	struct timeval	tv;
	useconds_t		timestamp;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philo->access_mutex);
	timestamp = (tv.tv_sec * 1000 + tv.tv_usec / 1000) - philo->start_time;
	pthread_mutex_unlock(philo->access_mutex);
	return (timestamp);
}

void	log_message(t_philo *philo, const char *message)
{
	useconds_t	timestamp;

	timestamp = get_timestamp(philo);
	pthread_mutex_lock(philo->log_mutex);
	pthread_mutex_lock(philo->access_mutex);
	if (philo->death_flag == 0)
		printf("%u %d %s\n", timestamp, philo->id, message);
	pthread_mutex_unlock(philo->access_mutex);
	pthread_mutex_unlock(philo->log_mutex);
}
