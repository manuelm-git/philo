/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tseutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:34:52 by manumart          #+#    #+#             */
/*   Updated: 2024/02/27 18:44:23 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isdead(void)
{
	pthread_mutex_lock(&philodata()->deathmutex);
	if (philodata()->deathstatus == 1)
	{
		pthread_mutex_unlock(&philodata()->deathmutex);
		return (1);
	}
	pthread_mutex_unlock(&philodata()->deathmutex);
	return (0);
}

int	output(t_philo *philo, char *message, char *color)
{
	pthread_mutex_lock(&philodata()->deathmutex);
	if (philodata()->deathstatus == 1)
	{
		pthread_mutex_unlock(&philodata()->deathmutex);
		return (1);
	}
	pthread_mutex_unlock(&philodata()->deathmutex);
	pthread_mutex_lock(&philodata()->msg);
	printf("%s%lu %d %s\n", color, get_time() - philodata()->start, philo->id,
		message);
	pthread_mutex_unlock(&philodata()->msg);
	return (0);
}

void	unlock_fork(t_philo *philo, t_fork *fork)
{
	while (!check_philo(philo))
	{
		pthread_mutex_lock(&fork->mutex);
		if (fork->istaken == 1)
		{
			fork->istaken = 0;
			pthread_mutex_unlock(&fork->mutex);
			return ;
		}
		else
			pthread_mutex_unlock(&fork->mutex);
	}
}

void	lock_fork(t_philo *philo, t_fork *fork)
{
	while (!check_philo(philo))
	{
		pthread_mutex_lock(&fork->mutex);
		if (fork->istaken == 0)
		{
			fork->istaken = 1;
			pthread_mutex_unlock(&fork->mutex);
			output(philo, "has taken a fork", IWHITE);
			break ;
		}
		else
			pthread_mutex_unlock(&fork->mutex);
	}
}
