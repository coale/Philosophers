/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:47:38 by aconta            #+#    #+#             */
/*   Updated: 2023/06/21 09:49:22 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eat(int id)
{
  printf("%d is eating\n");
  usleep(t_args.time_to_eat);
}

void think(int id)
{
  printf("%d is thinking\n");
  usleep(1);
}

void sleep(int id)
{
  printf("%d is sleeping\n");
  usleep(t_args.time_to_sleep);
}

void philo_routine(void *arg)
{
  
}