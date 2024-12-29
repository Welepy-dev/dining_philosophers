/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:10:18 by marcsilv          #+#    #+#             */
/*   Updated: 2024/12/28 11:40:05 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

typedef struct s_data t_data;

typedef struct s_ph
{
	int			id;
	long	meals;
	bool	is_full;
	long 	last_meal;
	t_data	*data;
}	t_ph;

struct s_data
{
	long 	n_ph;
	long	time_to_die;
	long	time_to_eat;
	long 	time_to_sleep;
	long 	number_of_meals;
	long 	start_simulation;
	bool 	end_simulation;
	sem_t	forks;
	sem_t 	write;
	bool 	processes_ready;
	long 	active_philosophers;
	t_ph 	*ph;
};

typedef enum e_status
{
	DEAD,
	EATING,
	SLEEPING,
	THINKING,
	TAKING_FIRST_FORK,
	TAKING_SECOND_FORK,
	FULL
}	t_status;

#endif
