/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorlov <lorlov@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:09:56 by lorlov            #+#    #+#             */
/*   Updated: 2025/10/02 13:41:24 by lorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int  parse_strict_pos_int(const char *s, int *out);
static int err_msg(const char *fmt);

int check_arguments(int argc, char **argv)
{
    int n_philos, t_die, t_eat, t_sleep, n_meals;

    if (argc < 5 || argc > 6)
        return err_msg(STR_USAGE_ERR);

    if (parse_strict_pos_int(argv[1], &n_philos))
		return err_msg(STR_INPUT_ARGS_ERR);
    if (parse_strict_pos_int(argv[2], &t_die))
		return err_msg(STR_INPUT_ARGS_ERR);
    if (parse_strict_pos_int(argv[3], &t_eat))
		return err_msg(STR_INPUT_ARGS_ERR);
    if (parse_strict_pos_int(argv[4], &t_sleep))
		return err_msg(STR_INPUT_ARGS_ERR);
    if (argc == 6 && parse_strict_pos_int(argv[5], &n_meals))
		return err_msg(STR_INPUT_ARGS_ERR);

    if (n_philos > MAX_PHILOS)
		return err_msg(STR_MAX_PHILOS_ERR);

    (void)t_die; (void)t_eat; (void)t_sleep; (void)n_meals;

    return 0;
}

static int  parse_strict_pos_int(const char *s, int *out)
{
    long long acc = 0;
    size_t i = 0;

    if (!s || !s[0])
		return (1);
    while (s[i]) 
	{
        if (s[i] < '0' || s[i] > '9') 
			return 1;
        acc = acc * 10 + (s[i] - '0');
        if (acc > INT_MAX) 
			return 1;
        i++;
    }
    if (acc == 0)
		return (1);
    *out = (int)acc;
    return (0);
}

static int err_msg(const char *fmt)
{
    if (fmt)
		fprintf(stderr, fmt, STR_PROG_NAME);
    return (1);
}