#include <time.h>

srand (time(NULL));
printf ("Random number between 0 and 99: %d\n", rand()%100);