/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:46:30 by aconta            #+#    #+#             */
/*   Updated: 2023/06/21 09:46:34 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_routine(void *args)
{
  ;
}

int main(int argc, char **argv)
{
  t_args args;
  
  if (check_args_num(argc) != -1 && check_only_numbers(argv) != -1 && check_int_limits(argv) != -1)
  {
    args.number_of_philosophers = ft_long_atoi(argv[0]);
    args.time_to_die = ft_long_atoi(argv[1]);
    args.time_to_eat = ft_long_atoi(argv[2]);
    args.time_to_sleep = ft_long_atoi(argv[3]);
    args.number_of_times_each_philosopher_must_eat = ft_long_atoi(argv[4]);
  }
}