//"4", "420", "200", "200"
//5 500 200 200
//150 800 200 200
// Do not test with more than 200 philosophers
// - Do not test with time_to_die or time_to_eat or time_to_sleep under 60 ms
// - Test with 1 800 200 200, the philosopher should not eat and should die!
// - Test with 5 800 200 200, no one should die!
// - Test with 5 800 200 200 7, no one should die and the simulation should stop when all the philosopher has eaten at least 7 times each.
// - Test with 4 410 200 200, no one should die!
// - Test with 4 310 200 100, a philosopher should die!
// - Test with 2 philosophers and check the different times (a death delayed by more than 10 ms is unacceptable).
// - Test with your values to check all the rules. Check if a philosopher dies at the right time if they don't steal forks, etc.


#include <stdio.h>
#include <sys/time.h>

int main(void)
{
	struct timeval time;
	struct timezone time_zone;
	int i;

	i = 0;
	i = gettimeofday(&time, &time_zone);
	return (0);
}
1626095337538
1626095370764