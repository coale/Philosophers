/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:48:40 by aconta            #+#    #+#             */
/*   Updated: 2023/06/14 10:48:40 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int check_args_num(int argc) {
  if (argc > 6 || argc < 5)
  {
    write(2, "Wrong number of arguments\n", 26);
    return (-1);
  }
  return (0);
}

int check_int_limits(char **argv) 
{
  int i;

  i = 0;
  while (argv[i]) 
  {
        if (ft_long_atoi(argv[i]) > 2147483647 || ft_long_atoi(argv[i]) < -2147483648)
        {
          write(2, "At least one of the args exceeds int limits\n", 44);
          return (-1);
        } 
        i++;
  }
  return (0);
}

int check_only_numbers(char **argv) {
  int i;
  int j;

  i = 1;
  j = 0;
  while (argv[i])
  {
    while (argv[i][j])
    {
      if (argv[i][j] < '0' || argv[i][j] > '9') 
      {
        write(2, "Arguments must be numbers\n", 26);
        return (-1);
      }
      j++;
    }
    j = 0;
    i++;
  }
  return (0);
}