/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeNclean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:31:42 by manumart          #+#    #+#             */
/*   Updated: 2024/02/25 17:39:43 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((unsigned long)(tv.tv_sec * 1000) + (unsigned long)(tv.tv_usec
			/ 1000));
}

int	clean_everything(t_philo *philo, t_fork *forks)
{
	int	i;

	i = -1;
	if (forks)
	{
		while (++i < philodata()->nphil)
			pthread_mutex_destroy(&forks[i].mutex);
		free(forks);
	}
	if (philo)
	{
		pthread_mutex_destroy(&philodata()->msg);
		pthread_mutex_destroy(&philodata()->deathmutex);
		free(philo);
	}
	return (0);
}
