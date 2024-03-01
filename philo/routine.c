/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:29:52 by manumart          #+#    #+#             */
/*   Updated: 2024/03/01 20:13:16 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *currentphilo)
{
	t_philo	*philo;

	philo = (t_philo *)currentphilo;
	philo->lasttimeeaten = get_time();
	if (philodata()->nphil % 2 != 0 && philo->id == philodata()->nphil)
		think(philo);
	if (philo->id % 2 == 0)
	{
		think(philo);
		wait(philo, philodata()->timetoeat);
	}
	while (philo->mealseaten < philodata()->timesmusteat && !check_philo(philo))
	{
		eat(philo);
		if (isdead())
			return (NULL);
		go_to_sleep(philo);
		usleep(1000);
		if (isdead())
			return (NULL);
		if (philo->mealseaten < philodata()->timesmusteat)
			think(philo);
	}
	return (NULL);
}
