/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:03:13 by ikrozas           #+#    #+#             */
/*   Updated: 2026/04/10 13:21:40 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
	{
		printf("Usa: ./philo nb_philo t_die t_eat t_sleep [nb_meals]\n");
		return (1);
	}
	if (!check_args(argc, argv))
	{
		printf("Error: Argumentos invalidos\n");
		return (1);
	}
	if (!init_data(&data, argc, argv))
	{
		printf("Error: Fallo en la inicializacion de datos\n");
		return (1);
	}
	philos = malloc(sizeof(t_philo) * data.nb_philos);
	if (!philos)
	{
		return (1);
	}
	init_philos(philos, &data);
	return (0);
}
