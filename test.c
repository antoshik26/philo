//"4", "420", "200", "200"
//5 500 200 200
//150 800 200 200

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