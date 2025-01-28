/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:16:36 by marcsilv          #+#    #+#             */
/*   Updated: 2025/01/27 16:36:32 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		parse_args(ac, av, &data);
		data_init(&data);
		sim_start(&data);
		clean_and_exit(&data);
	}
	else
		error_msg("Input Error\n" YELLOW
			"Please enter: ./philo <no. of philos> <time_to_die> "
			"<time_to_eat> <time_to_sleep> <max_meals> (optional)\n"
			"For example: ./philo 5 800 200 200 7" RESET);
	return (0);
}

/*
 * If the input is correct, there are four stages:
 *
 * 1. parse args
 * 	Nothing unusual here, we just get the the input and fill general data like timestamps,
 * 	number of philo and times to eat
 *
 * 2. Initialization of data
 * 	Here we:
 * 		initialize some general data, but also allocate memory for the philosophers and forks
 * 		we initialize our mutexes to acess memory for philosophers and for writing data, not forgetting the forks
 *		specifically the philos, we initialize their atributes and assign forks,
 *			the logic for fork assignment:
 *				if odd, his right fork is equal to its index on the array, and left is assigned to the next fork
 *				if is even, the left fork is assigned to the current index the right fork is assigned to the next fork
 * 3. simulation 
 * 	Here we handle 3 scenarios first:
 * 		1. meals total == 0
 * 			we just return.
 * 		2. only one philo
 * 			this logic is not very complicated, the philo takes a fork, and waits continuesly for the other
 * 		3. normal input:
 * 			- create all philos and the monitor
 * 			- in the simulation it runs a spinlock until every thread is ready
 * 			- syncronize
 * 			- and run the program until the end time boolean is set to false
 * 			- the program will run the regular routine of the philosopher
 * 4. cleaning
 * 	Here we destroy all mutexes, and free our arrays of forks and philos
 *
 * The monitor:
 *	the monitor waits for the philos to be ready, when they are it monitors the philos until one of the end_time bools of one of them is set to false
 *
 */
