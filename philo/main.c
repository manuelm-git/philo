/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:52:04 by manumart          #+#    #+#             */
/*   Updated: 2024/02/29 17:37:17 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	all_prints(void)
// {
// 	if (philodata()->nphil)
// 		printf(" [num philo] %ld philos\n", philodata()->nphil);
// 	if (philodata()->timetodie)
// 		printf(" [time to die] %ld ms\n", philodata()->timetodie);
// 	if (philodata()->timesmusteat)
// 		printf(" [time to eat] %ld ms\n", philodata()->timetoeat);
// 	if (philodata()->timetodie)
// 		printf(" [time to sleep] %ld ms\n", philodata()->timetosleep);
// 	if (philodata()->timetosleep)
// 		printf(" [num times to eat] %ld meals\n\n", philodata()->timesmusteat);
// }
// t_philo *philo(void)
// {
//     static t_philo philo;

//     return(&philo);
// }
t_philodata	*philodata(void)
{
	static t_philodata	data;

	return (&data);
}

int	givevaluetophil(int argc, char **argv)
{
	(void)argc;
	philodata()->nphil = ft_atoi(argv[1]);
	philodata()->timetodie = ft_atoi(argv[2]);
	philodata()->timetoeat = ft_atoi(argv[3]);
	philodata()->timetosleep = ft_atoi(argv[4]);
	if (argv[5])
		philodata()->timesmusteat = ft_atoi(argv[5]);
	else
		philodata()->timesmusteat = __INT_MAX__;
	if (philodata()->nphil <= 0 || philodata()->nphil > 200
		|| (int)philodata()->timetodie < 0 || (int)philodata()->timetoeat < 0
		|| (int)philodata()->timetosleep < 0)
		return (ft_exit_error("Input Error Limits"));
	if (philodata()->timesmusteat <= 0 || (argv[5]
			&& philodata()->timesmusteat >= INT_MAX))
		return (ft_exit_error(" ;("));
	philodata()->start = get_time();
	philodata()->deathstatus = 0;
	pthread_mutex_init(&philodata()->deathmutex, NULL);
	pthread_mutex_init(&philodata()->msg, NULL);
	return (0);
}

int	checkargs(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (ft_exit_error("Invalid number of arguments"));
	else if (argc >= 5 && argc <= 6)
	{
		while (argv[i] && i <= argc)
		{
			if (ft_isstralldigits(argv[i]))
				return (ft_exit_error("Invalid input"));
			i++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (checkargs(argc, argv))
		return (1);
	if (givevaluetophil(argc, argv))
		return (1);
	if (allocate(&philodata()->philo))
		return (1);
	if (init_threads(philodata()->philo))
	{
		clean_everything(philodata()->philo, philodata()->philo->forks);
		return (1);
	}
	return (0);
}

// passa com limites?
// passa com ++ ou -- com input?
// e mais umas merdas
// remove