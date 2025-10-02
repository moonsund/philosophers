/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorlov <lorlov@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:10:08 by lorlov            #+#    #+#             */
/*   Updated: 2025/10/02 15:12:38 by lorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    if (check_arguments(argc, argv))
        return (EXIT_FAILURE);








        
    for (int i = 1; argv[i]; i++)
        printf("%s\n", argv[i]);
    return (EXIT_SUCCESS);
}