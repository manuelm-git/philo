/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:29:27 by manumart          #+#    #+#             */
/*   Updated: 2024/03/01 18:25:31 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philodata()->nphil)
		if (pthread_create(&philo[i].philo, NULL, &routine, &philo[i]))
			return (1);
	i = -1;
	while (++i < philodata()->nphil)
		if (pthread_join(philo[i].philo, NULL))
			return (1);
	clean_everything(philodata()->philo, philodata()->philo->forks);
	return (0);
}

int	attribute_data(t_philo **philo, t_fork *forks)
{
	int	i;

	i = -1;
	while (++i < philodata()->nphil)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].mealseaten = 0;
		(*philo)[i].forks = forks;
	}
	i = -1;
	while (++i < philodata()->nphil)
	{
		forks[i].istaken = 0;
		if (pthread_mutex_init(&forks[i].mutex, NULL))
			return (1);
	}
	return (0);
}

int	allocate(t_philo **philo)
{
	t_fork	*forks;

	forks = NULL;
	(*philo) = (t_philo *)malloc(sizeof(t_philo) * philodata()->nphil);
	if (!*philo)
	{
		clean_everything(*philo, forks);
		return (1);
	}
	forks = (t_fork *)malloc(sizeof(t_fork) * philodata()->nphil);
	if (!forks)
	{
		clean_everything(NULL, forks);
		return (1);
	}
	if (attribute_data(philo, forks))
		return (1);
	return (0);
}
