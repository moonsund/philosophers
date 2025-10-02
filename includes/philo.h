#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>    // EXIT_FAILURE, EXIT_SUCCESS
#include <limits.h>     // INT_MAX
# include <fcntl.h>     // open
# include <unistd.h>   // close, pipe, fork, read, write
# include <stdio.h>    // perror
# include <errno.h>    // errno
# include <sys/wait.h> // waitpid
# include <stdbool.h>

# define MAX_PHILOS 200
# define STR_PROG_NAME	"philo:"
# define STR_USAGE_ERR	"%s usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"
# define STR_INPUT_ARGS_ERR "%s\n invalid input: arguments must be positive integers"
# define STR_MAX_PHILOS_ERR "%s\n invalid input: 200 philos max\n"

// parce.c
int check_arguments(int argc, char **argv);



#endif
