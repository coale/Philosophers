/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:23:55 by aconta            #+#    #+#             */
/*   Updated: 2023/07/02 18:17:18 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo {
	int				id;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_eat_goal;
	int				num_eat_count;
	useconds_t		last_meal_time;
	useconds_t		start_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*log_mutex;
	pthread_mutex_t	*access_mutex;
	int				death_flag;
}	t_philo;

typedef struct s_mutexes {
	pthread_mutex_t	*forks;
	pthread_mutex_t	log_mutex; 
	pthread_mutex_t	access_mutex;
}	t_mutexes;

// UTILS
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				check_args(int argc, char **argv);
useconds_t		get_timestamp(t_philo *philo);
void			log_message(t_philo *philo, const char *message);
// THREAD
void			*philo_solo_thread(void *arg);
void			ph_thread_norme(t_philo *philo);
void			*philo_thread(void *arg);
void			create_philo_threads(pthread_t *threads, t_philo *philos);
void			wait_for_philo_threads(pthread_t *threads, int num_philo);
// PHILO_ACTIONS
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
//INIT
void			init_for_norme(t_philo *philos, t_mutexes *mut, int i);
void			init_philo(t_philo *philos, t_mutexes *mut, int num_philo);
//FORKS
pthread_mutex_t	*create_forks(int num_forks);
void			destroy_forks(pthread_mutex_t *forks, int num_forks);
//DEATH
void			check_death(t_philo *philo);
void			*while_death(t_philo *philo, int n_philo, int n_eat, int i);
void			*death_thread(void *arg);
void			start_death_threads(t_philo *philos);

#endif
