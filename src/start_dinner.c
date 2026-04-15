/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:35:11 by ikrozas           #+#    #+#             */
/*   Updated: 2026/04/15 14:43:09 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

int	start_dinner(t_data *data, t_philo *philos)
{
	pthread_t	observer;
	int			i;

	data->start_time = get_time();
	i = 0;
	while (i < data->nb_philos)
	{
		philos[i].last_meal = data->start_time;
		if (pthread_create(&philos[i].thread, NULL, &philo_routine,
				&philos[i]) != 0)
			return (0);
		i++;
	}
	if (pthread_create(&observer, NULL, &monitor_routine, philos) != 0)
		return (0);
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(observer, NULL);
	return (1);
}
