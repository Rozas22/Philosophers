/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:33:25 by ikrozas           #+#    #+#             */
/*   Updated: 2026/03/24 15:04:50 by ikrozas          ###   ########.fr       */
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


int arg_is_num(char *str);
int check_args(int argc, char **argv);
int ft_atoi(const char *str);
long long   get_time(void);
int init_data(t_data *data, int argc, char **argv);
int init_philos(t_philo *philos, t_data *data);
void    *philo_routine(void *arg);
int start_dinner(t_data *data, t_philo *philos);


#endif