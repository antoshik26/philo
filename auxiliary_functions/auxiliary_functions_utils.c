#include "philo.h"

int	allocate_lst_new_philo(int numer_philo, t_all_progect *all, \
		t_philo *new_list)
{
	new_list->numer_philo = numer_philo;
	new_list->time_to_die = all->time_to_die;
	new_list->time_to_eat = all->time_to_eat;
	new_list->time_to_sleap = all->time_to_sleap;
	new_list->count_eat = all->count_philo_eat;
	new_list->mutex_philo_said = &all->mutex_philo_said;
	new_list->key_die_philo = &all->key_die_philo;
	new_list->time_start = gettime();
	new_list->time_to_last_eat = new_list->time_start;
	return (0);
}

t_philo	*ft_lstnew_philo(int numer_philo, t_all_progect *all)
{
	t_philo	*new_list;
	t_forks	*fork;

	fork = all->forks;
	new_list = (t_philo *)malloc(sizeof(t_philo));
	if (new_list == NULL)
		return (NULL);
	allocate_lst_new_philo(numer_philo, all, new_list);
	while (fork->numer_fork != numer_philo)
	{
		fork = fork->next;
	}
	new_list->left_hand = fork;
	fork = fork->next;
	if (fork == NULL)
		new_list->right_hand = all->forks;
	else
		new_list->right_hand = fork;
	new_list->next = NULL;
	return (new_list);
}

t_forks	*ft_lstnew_fork(int numer_fork)
{
	t_forks	*new_list;

	new_list = (t_forks *)malloc(sizeof(t_forks));
	if (new_list == NULL)
		return (NULL);
	new_list->numer_fork = numer_fork;
	pthread_mutex_init(&new_list->mutex_fork, NULL);
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstadd_back_philo(t_philo **lst, t_philo *new)
{
	t_philo	*a;

	a = *lst;
	if (!*lst && new)
	{
		*lst = new;
	}
	while (a)
	{
		if (a->next == NULL)
		{
			a->next = new;
			break ;
		}
		else
			a = a->next;
	}
}

void	ft_lstadd_back_forks(t_forks **lst, t_forks *new)
{
	t_forks	*a;

	a = *lst;
	if (!*lst && new)
	{
		*lst = new;
	}
	while (a)
	{
		if (a->next == NULL)
		{
			a->next = new;
			break ;
		}
		else
			a = a->next;
	}
}
