#include "philo.h"

t_philo	*ft_lstnew_philo(int numer_philo, t_all_progect *all)
{
	t_philo *new_list;

	new_list = (t_philo *)malloc(sizeof(t_philo));
	if (new_list == NULL)
		return (NULL);
	new_list->numer_philo = numer_philo;
	new_list->time_to_die = all->time_to_die;
	new_list->time_to_eat = all->time_to_eat;
	new_list->time_to_sleap = all->time_to_sleap;
	new_list->count_eat = all->count_philo_eat;
	new_list->time_to_last_eat = 0;
	new_list->next = NULL;
	return (new_list);
}

t_forks	*ft_lstnew_fork(int numer_fork)
{
	t_forks *new_list;

	new_list = (t_forks *)malloc(sizeof(t_forks));
	if (new_list == NULL)
		return (NULL);
	new_list->numer_forks = numer_fork;
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstadd_back_philo(t_philo **lst, t_philo *new)
{
	t_list *a;

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
	t_list *a;

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