/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:33:25 by ikrozas           #+#    #+#             */
/*   Updated: 2026/03/23 12:40:52 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
    int nb_philos;
    size_t  time_to_die;
    size_t  time_to_eat;
    size_t  time_to_sleep;
    int meals_needed;
    pthread_mutex_t *forks;
    pthread_mutex_t write_lock;
}   t_data;

typedef struct s_philo
{
    int id;
    pthread_t   thread;
    size_t  last_meal;
    int meals_eaten;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;
    t_data  *data;
}   t_philo;


#endif