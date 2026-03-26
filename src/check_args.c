/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:42:10 by ikrozas           #+#    #+#             */
/*   Updated: 2026/03/24 13:34:29 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philosophers.h"

int arg_is_num(char *str)
{
    int i;

    i = 0;
    if (str[i] == '\0')
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int check_args(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!arg_is_num(argv[i]))
            return (0);
        if (ft_atoi(argv[i]) <= 0)
            return (0);
        i++;
    }
    return (1);
}