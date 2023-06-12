/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <aconta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:23:50 by aconta            #+#    #+#             */
/*   Updated: 2023/06/12 10:23:50 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *helloWorld()
{
    sleep(1);
    printf("Hello World \n");
    return NULL;
}

/* int philo_create()
{

} */

int main()
{
    pthread_t thread_id;
    int i = 0;

    while (i < 3)
    {
        printf("Before Thread %d\n", i);
        pthread_create(&thread_id, NULL, helloWorld, NULL);
        //pthread_join(thread_id, NULL);
        printf("After Thread\n");
        i++;
    }
    exit(0);
}