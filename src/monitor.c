/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:35:06 by ikrozas           #+#    #+#             */
/*   Updated: 2026/04/14 20:50:32 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

int is_dead(t_data *data)
{
    int stop;

    pthread_mutex_lock(&data->dead_lock);
    stop = data->dead_flag;
    pthread_mutex_unlock(&data->dead_lock);
    return (stop);
}

int philosopher_dead(t_philo *philo)
{
    long long   now;
    
    pthread_mutex_lock(&philo->data->meal_lock);
    now = get_time();
    if ((now - philo->last_meal) >= (long long)philo->data->time_to_die)
    {
        pthread_mutex_lock(&philo->data->dead_lock);
        philo->data->dead_flag = 1;
        pthread_mutex_unlock(&philo->data->dead_lock);
        pthread_mutex_lock(&philo->data->write_lock);
        printf("%lld %d died\n", now - philo->data->start_time,
                philo->id);
        pthread_mutex_unlock(&philo->data->write_lock);
        pthread_mutex_unlock(&philo->data->meal_lock);
        return (1);
    }
    pthread_mutex_unlock(&philo->data->meal_lock);
    return (0);
}

int check_total_meals(t_philo *philos)
{
    int i;
    int full_philos;
    
    if (philos[0].data->meals_needed == -1)
        return (0);
    i = 0;
    full_philos = 0;
    while (i < philos[0].data->nb_philos)
    {
        pthread_mutex_lock(&philos[0].data->meal_lock);
		if (philos[i].meals_eaten >= philos[0].data->meals_needed)
			full_philos++;
		pthread_mutex_unlock(&philos[0].data->meal_lock);
		i++;
    }
    if (full_philos == philos[0].data->nb_philos)
	{
		pthread_mutex_lock(&philos[0].data->dead_lock);
		philos[0].data->dead_flag = 1;
		pthread_mutex_unlock(&philos[0].data->dead_lock);
		return (1);
	}
	return (0);
}

void    *monitor_routine(void *arg)
{
    t_philo *philos;
    int     i;

    philos = (t_philo *)arg;
    while (1)
    {
        i = 0;
        while (i < philos[0].data->nb_philos)
        {
            if (philosopher_dead(&philos[i]))
                return (NULL);
            i++;
        }
        if (check_total_meals(philos))
            return (NULL);
        usleep(1000);
    }
    return (NULL);
}
