#include "philo.h"

int	checking_for_validity(t_all_progect *all)
{
	if (all->count_philos <= 0 || all->time_to_die <= 0 || \
			all->time_to_eat <= 0 || all->time_to_sleap <= 0)
		return (-1);
	return (0);
}

int	parser_philo(t_all_progect *all, int argc, char **argv)
{
	all->count_philos = ft_atoi(argv[1]);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_eat = ft_atoi(argv[3]);
	all->time_to_sleap = ft_atoi(argv[4]);
	if (argc == 6)
	{
		all->count_philo_eat = ft_atoi(argv[5]);
		if (all->count_philo_eat <= 0)
			return (-1);
	}
	else
		all->count_philo_eat = -1;
	if (all->count_philos == -1 || all->time_to_die == -1 || \
			all->time_to_eat == -1 || all->time_to_sleap == -1)
		return (-1);
	if (checking_for_validity(all) == -1)
	{
		printf("Wrong argument");
		return (-1);
	}
	return (0);
}

int	creat_fork(t_all_progect *all)
{
	int			i;
	t_forks		*fork;

	i = 1;
	while (i < all->count_philos + 1)
	{
		fork = ft_lstnew_fork(i);
		if (fork == NULL)
			return (-1);
		ft_lstadd_back_forks(&all->forks, fork);
		i++;
	}
	return (0);
}

int	creat_philo(t_all_progect *all)
{
	int			i;
	t_philo		*philo_one;

	i = 1;
	while (i < all->count_philos + 1)
	{
		philo_one = ft_lstnew_philo(i, all);
		if (philo_one == NULL)
			return (-1);
		ft_lstadd_back_philo(&all->philos, philo_one);
		i++;
	}
	return (0);
}

int	parser(t_all_progect *all, int argc, char **argv)
{
	int	i;

	if (argc <= 4 || argc >= 6)
	{
		printf("Неверное количество аргументов\n");
		return (-1);
	}
	i = ft_atoi(argv[1]);
	if (i < 0)
	{
		printf("Неверное количество философов\n");
		return (-1);
	}
	if (parser_philo(all, argc, argv) == -1)
		return (-1);
	if (creat_fork(all) == -1)
		return (-1);
	if (creat_philo(all) == -1)
		return (-1);
	return (0);
}
