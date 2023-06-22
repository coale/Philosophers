/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:46:30 by aconta            #+#    #+#             */
/*   Updated: 2023/06/22 09:22:59 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char* argv[]) {
    DiningTable table;
    int i;
    
    i = 0;
    initialize_table(&table, argc, argv);
    while (i < table.number_of_philosophers) 
    {
        PhilosopherData* data = malloc(sizeof(PhilosopherData));
        data->table = &table;
        data->philo_id = i;
        pthread_create(&table.philosophers[i], NULL, philosopher, data);
        i++;
    }
    i = 0;
    while (i < table.number_of_philosophers) 
    {
        pthread_join(table.philosophers[i], NULL);
        i++;
    }
    destroy_table(&table);
    return 0;
}