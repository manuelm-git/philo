/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:31:48 by manumart          #+#    #+#             */
/*   Updated: 2024/03/01 20:17:40 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait(t_philo *philo, unsigned long time)
{
	unsigned long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (check_philo(philo))
			return ;
		usleep(time / 10);
	}
	check_philo(philo);
}

int	check_philo(t_philo *philo)
{
	pthread_mutex_lock(&philodata()->deathmutex);
	if (get_time() - philo->lasttimeeaten >= philodata()->timetodie)
	{
		if (philodata()->deathstatus == 1)
		{
			pthread_mutex_unlock(&philodata()->deathmutex);
			return (1);
		}
		pthread_mutex_lock(&philodata()->msg);
		printf("%s%lu %d died\n", RED, get_time() - philodata()->start,
			philo->id);
		pthread_mutex_unlock(&philodata()->msg);
		philodata()->deathstatus = 1;
		pthread_mutex_unlock(&philodata()->deathmutex);
		return (1);
	}
	pthread_mutex_unlock(&philodata()->deathmutex);
	return (0);
}

void	think(t_philo *philo)
{
	output(philo, "is thinking", G_CYAN);
}

void	go_to_sleep(t_philo *philo)
{
	if (philo->mealseaten < philodata()->timesmusteat)
	{
		output(philo, "is sleeping", YELLOW);
		wait(philo, philodata()->timetosleep);
	}
}

int	eat(t_philo *philo)
{
	int	rightfork;
	int	leftfork;

	if (philo->id == 1)
	{
		leftfork = philodata()->nphil - 1;
		rightfork = philo->id - 1;
	}
	else
	{
		leftfork = philo->id - 2;
		rightfork = philo->id - 1;
	}
	lock_fork(philo, &philo->forks[rightfork]);
	lock_fork(philo, &philo->forks[leftfork]);
	if (isdead())
		return (0);
	output(philo, "is eating", GREEN);
	philo->lasttimeeaten = get_time();
	wait(philo, philodata()->timetoeat);
	unlock_fork(philo, &philo->forks[rightfork]);
	unlock_fork(philo, &philo->forks[leftfork]);
	philo->mealseaten++;
	return (1);
}
