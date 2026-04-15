/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:35:09 by ikrozas           #+#    #+#             */
/*   Updated: 2026/04/15 14:42:46 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

void	print_status(t_philo *philo, char *status)
{
	long long	time;

	pthread_mutex_lock(&philo->data->write_lock);
	if (!is_dead(philo->data))
	{
		time = get_time() - philo->data->start_time;
		printf("%lld %d %s\n", time, philo->id, status);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	eat_action(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, "has taken a fork");
	if (philo->data->nb_philos == 1)
	{
		ft_usleep(philo->data->time_to_die, philo->data);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	print_status(philo, "is eating");
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2, philo->data);
	while (!is_dead(philo->data))
	{
		eat_action(philo);
		if (is_dead(philo->data))
			break ;
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
		if (is_dead(philo->data))
			break ;
		print_status(philo, "is thinking");
		if (philo->id % 2 == 0)
			ft_usleep(philo->data->time_to_eat / 2, philo->data);
	}
	return (NULL);
}
