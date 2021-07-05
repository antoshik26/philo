#include "philo.h"

void clean(t_philo *philo, t_forks *forks)
{
	t_forks *tmp;

	tmp = forks
	while(fors)
	{
		tmp = forks->next;
		free(forks);
		forks = tmp;
	}
}

int main(int argc, char **argv)
{
	t_all_progect progect;
	int i;

	i = 0;
	if (parser(&progect) == -1)
		return (-1);
	live_philo(&progect);
	clean(&progect);
	return (0);
}