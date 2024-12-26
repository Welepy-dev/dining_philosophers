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
		error_msg("Input Error\n" YELLOW "Please enter: ./philo <no. of philos> <time_to_die> "
			"<time_to_eat> <time_to_sleep> <max_meals> (optional)\n"
			"For example: ./philo 5 800 200 200 7" RESET);
	return (0);
}
