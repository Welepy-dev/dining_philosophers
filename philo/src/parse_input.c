/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:27:16 by marcsilv          #+#    #+#             */
/*   Updated: 2024/12/26 17:54:14 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static inline bool	is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static long	ft_atol(const char *str, int tag)
{
	int	num;

	num = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		er("Use only positive integers");
	if (!is_digit(*str))
		er("Invalid input, use actual numbers");
	while (*str && is_digit(*str))
		num = (num * 10) + (*(str++) - '0');
	if (num > INT_MAX)
		er("Input number too large");
	if (tag == 1 && num < 1)
		er("You must have at least 1 philosopher");
	if (tag == 2 && num < 60)
		er("Timestamps must be at least 60ms");
	if (tag == 3 && num < 1)
		er("Philosophers must eat at least 1 time");
	return (num);
}

void	parse_args(int ac, char **av, t_data *data)
{
	data->ph_total = ft_atol(av[1], 1);
	data->time_to_die = (ft_atol(av[2], 2) * 1e3);
	data->time_to_eat = (ft_atol(av[3], 2) * 1e3);
	data->time_to_sleep = (ft_atol(av[4], 2) * 1e3);
	if (ac == 6)
		data->meals_total = ft_atol(av[5], 3);
	else
		data->meals_total = -1;
}
