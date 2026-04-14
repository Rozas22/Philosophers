/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:03:13 by ikrozas           #+#    #+#             */
/*   Updated: 2026/04/14 18:57:26 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
	{
		printf("Use: ./philo nb_philo t_die t_eat t_sleep [nb_meals]\n");
		return (1);
	}
	if (!check_args(argc, argv))
	{
		printf("Error: Invalids Arguments\n");
		return (1);
	}
	if (!init_data(&data, argc, argv))
	{
		printf("Error: Data inizalization failure\n");
		return (1);
	}
	philos = malloc(sizeof(t_philo) * data.nb_philos);
	if (!philos)
		return (clean_all(&data, NULL), 1);
	init_philos(philos, &data);
	start_dinner(&data, philos);
	clean_all(&data, philos);
	return (0);
}
