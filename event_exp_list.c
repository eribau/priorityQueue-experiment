#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "list_double.h"

#define LOOPS 1000000
#define MEAS_ERR 4000
#define BUFFER 10000
#define EVENTS 10
#define INCREMENT 10

// Modified code taken from assignment in ID1200 Operating systems
int rand_double(int max, int min) {
  /* k is log(MAX/MIN) */
	double k = log(((double) max) / min);

	/* r is [0..k] */
	double r  = ((double) (rand() % (int) (k * 10000))) / 10000;

	/* size  is [0..MAX] */
	double size = (int) ((double) max / exp(r));

  return size;
}

void main() {
  struct timespec t_start, t_stop;
  link list = init();

  short buffer[BUFFER];
  for(int i = 0; i < BUFFER; i++) {
    buffer[i] = 0;
  }

  int p = 0;
  for(int l = 0; l < 11; l++) {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t_start);
		list = insert(list, 1.0);
    for(int i = 0; i < p; i++) {
      double t = removeMin(list);
			int events = rand() % EVENTS;			// Generate a number of events
			for(int n = 0; n < events; n++) {
				double increment = rand_double(INCREMENT, 1);
				list = insert(list, t + increment);
			}
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t_stop);

    long wall_sec = t_stop.tv_sec - t_start.tv_sec;
    long wall_nsec = t_stop.tv_nsec - t_start.tv_nsec;
    long wall_msec = (wall_sec * 1000) + ((wall_nsec - MEAS_ERR)/ 1000000);

    printf("%ld\t%d\n", wall_msec, p);
    p = p + 500;
  }

}
