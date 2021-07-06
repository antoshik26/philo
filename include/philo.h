#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <pthread.h>

typedef struct	s_philo
{
	int			numer_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleap;
	int			time_to_last_eat;
	int					count_eat;
	pthread_t			flow_philo;
	struct s_philo		*next;
}				t_philo;

typedef struct	s_forks
{
	int					numer_forks;
	pthread_mutex_t		mutex_fork;
	struct s_forks		*next;
}				t_forks;

typedef struct	s_all_progect
{
	int			count_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleap;
	int			count_philo_eat;
	t_philo		*philos;
	t_forks		*forks;
}				t_all_progect;

int				parser(t_all_progect *all, int argc, char **argv);
int				live_philo(t_all_progect *all);
t_philo			*ft_lstnew_philo(int numer_philo, t_all_progect *all);
t_forks			*ft_lstnew_fork(int numer_fork);
void			ft_lstadd_back_philo(t_philo **lst, t_philo *new);
void			ft_lstadd_back_forks(t_forks **lst, t_forks *new);
int				ft_atoi(const char *str);
#endif