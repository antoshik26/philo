#include "philo.h"

int checking_for_validity(t_all_progect *all)
{
	if (all->count_philo <= 0 || all->time_to_die <=0 || all->time_to_eat <= 0 || all->time_to_sleap <= 0)
		return (-1);
	return (0);
}

int parset_philo(t_all_progect *all, int argc, char **argv)
{
	all->count_philo = ft_itoa(argv[1]);
	all->time_to_die = ft_itoa(argv[2]);
	all->time_to_eat = ft_itoa(argv[3]);
	all->time_to_sleap = ft_itoa(argv[4]);
	if (argc = 5)
	{
		all->count_philo_eat = ft_itoa(argv[5]);
		if (all->count_philo_eat == -1 || all->count_philo_eat <= 0)
			return (-1)
	}
	else
		all->count_philo_eat == -1;
	if (all->count_philo == -1 || all->time_to_die == -1 || all->time_to_eat == -1 || all->time_to_sleap == -1)
		return (-1);
	if (checking_for_validity(all) == -1)
		return (-1);
	return (0);
}

int creat_fork(t_all_progect *all)
{
	int i;
	t_forks *fork;

	i = 0;
	while (i < all->count_philo)
	{
		fork = ft_lstnew(philo->numer_philo);
		if (fork == -1)
			return (-1);
		ft_lstadd_back(&all->forks, fork);
		i--;
	}
	return (0);
}

int creat_philo(t_all_progect *all)
{
	int i;
	int	j
	t_philo *philo_one;
	
	i = 0;
	while (i < all->count_philo)
	{
		philo_one = ft_lstnew(j, argc);
		if (philo_one == -1)
			return (-1);
		ft_lstadd_back(&all->philos, philo_one);
		i++;
	}
	return (0);
}

int parser(t_all_progect *all, int argc, char **argv)
{
	if (argc < 4 || argc > 6) 
	{
		write(1, "неверное количество аргументов", 1);
		return (-1);
	}
	i = ft_itoa(argv[1]);
	if (i < 0)
	{
		write(1, "неверное количество философов", 1);
		return (-1);
	}
	if (parser_philo(all, argc, argv) == -1)
		return (-1);
	if (creat_fork(all) == -1)
		return (-1);
	if (creat_philo(all) == -1)
		return (-1);
	return(0);
}
