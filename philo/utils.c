/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:35:16 by manumart          #+#    #+#             */
/*   Updated: 2024/02/27 18:45:52 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_putstr_toerr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	return (0);
}

int	ft_isstralldigits(char *str)
{
	int	i;

	i = 0;
	if (!str[i] || !str[0])
		return (1);
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == '+')
			i++;
		if (i == 0 && str[i] == '-')
			return (1);
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	isnegative(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

long	ft_atoi(char *str)
{
	long	i;
	int		pn;
	long	num;

	i = 0;
	num = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	pn = isnegative(str[i]);
	if (pn == -1)
		return (ft_exit_error("Negative input"));
	while (str[i])
	{
		if (i == 0 && str[0] == '+')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + str[i] - '0';
			i++;
		}
	}
	if (num > 0 && num < INT_MAX)
		return (num * pn);
	else
		return (0);
}

int	ft_exit_error(char *msg)
{
	ft_putstr_toerr("Error:");
	ft_putstr_toerr(msg);
	ft_putstr_toerr("\n");
	return (1);
}
