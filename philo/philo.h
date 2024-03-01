/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:00:43 by manumart          #+#    #+#             */
/*   Updated: 2024/02/27 21:47:08 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

/*
** Colors
*/
# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"
# define RED "\033[0;91m"
# define YELLOW "\033[0;93m"
# define IWHITE "\033[0;97m"

typedef struct s_fork
{
	int				istaken;
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_death
{
	int				deathstatus;
	pthread_mutex_t	deathmutex;
}					t_death;

typedef struct s_philo
{
	int				id;
	int				mealseaten;
	unsigned long	lasttimeeaten;
	pthread_t		philo;
	t_fork			*forks;
}					t_philo;
typedef struct s_philodata
{
	long			nphil;
	long			timetoeat;
	long			timetosleep;
	long			timesmusteat;
	long			eatamount;
	unsigned long	timetodie;
	unsigned long	start;
	pthread_mutex_t	msg;
	int				deathstatus;
	pthread_mutex_t	deathmutex;
	t_philo			*philo;

}					t_philodata;

t_philodata			*philodata(void);
int					ft_isstralldigits(char *str);
long				ft_atoi(char *str);
int					checkargs(int argc, char **argv);
int					ft_putstr_toerr(char *str);
int					ft_exit_error(char *msg);
int					init_threads(t_philo *philo);
unsigned long		get_time(void);
int					isdead(void);
int					output(t_philo *philo, char *message, char *color);
void				unlock_fork(t_philo *philo, t_fork *fork);
void				lock_fork(t_philo *philo, t_fork *fork);
int					clean_everything(t_philo *philo, t_fork *forks);
int					attribute_data(t_philo **philo, t_fork *forks);
int					allocate(t_philo **philo);
int					check_philo(t_philo *philo);
void				think(t_philo *philo);
void				go_to_sleep(t_philo *philo);
int					isdead(void);
int					output(t_philo *philo, char *message, char *color);
void				*routine(void *currentphilo);
void				wait(t_philo *philo, unsigned long time);
void				unlock_fork(t_philo *philo, t_fork *fork);
void				lock_fork(t_philo *philo, t_fork *fork);
int					eat(t_philo *philo);

#endif