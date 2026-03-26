/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:35:11 by ikrozas           #+#    #+#             */
/*   Updated: 2026/03/24 15:02:46 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

int start_dinner(t_data *data, t_philo *philos)
{
    int i;

    i = 0;
    while (i < data->nb_philos)
    {
        if (pthread_create(&philos[i].thread, NULL, &philo_routine, &philos[i]) != 0)
            return (0);
        i++;
    }
    i = 0;
    while (i < data->nb_philos)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
    return (1);
}
