#include <pthread.h>

volatile static char buf[bufSize];
volatile static int head = 0;
volatile static int tail = 0;
volatile static int n = 0;

static pthread_mutex_t bufMutex;
static pthread_cond_t  bufEmptyCv;
static pthread_cond_t  bufFullCv;

void put(long id, char ch) {
  pthread_mutex_lock(&bufMutex);        // start of CS
  
  while (n == bufSize) {
    pthread_cond_wait(&bufFullCv, &bufMutex);
  }
  buf[tail] = ch; 
  tail = (tail + 1) % bufSize; 
  ++n;
  pthread_cond_signal(&bufEmptyCv);
  
  pthread_mutex_unlock(&bufMutex);      // end of CS
}

char get(long id) {
  char ch;  
  pthread_mutex_lock(&bufMutex);        // start of CS

  while (n == 0) {
    printf("Consumer thread %ld going to wait\n", id);
    pthread_cond_wait(&bufEmptyCv, &bufMutex);
  }
  ch = buf[head];
  head = (head + 1) % bufSize; 
  --n;  
  printf("Consumer thread %ld ready: n = %d\n", id, n);
  pthread_cond_signal(&bufFullCv);
  
  pthread_mutex_unlock(&bufMutex);      // end of CS
  return ch;
}

void* produce(void* t) {
  for (int i = 0; i < maxCount; ++i) {
    put(myId, 'x');
    usleep(800000);
  }
  pthread_exit(0);
}

void* consume(void* t) {
  for (int i = 0; i < maxCount; ++i) {
    get(myId);
    usleep(200000);
  }
  pthread_exit(0);
}


int main(int argc, char *argv[])
{
  long t[numThreads] = {1, 2, 3, 4};
  pthread_t p1;
  pthread_t p2;
  pthread_t c1;
  pthread_t c2;
  pthread_attr_t attr;
  
  // Initialize mutex and condition variable objects
  pthread_mutex_init(&bufMutex, 0);
  pthread_cond_init (&bufEmptyCv, 0);
  pthread_cond_init (&bufFullCv, 0);

  // For portability, explicitly create threads in a joinable state
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_create(&p1, &attr, produce, (void*)t[0]);
  pthread_create(&p2, &attr, produce, (void*)t[1]);
  pthread_create(&c1, &attr, consume, (void*)t[2]);
  pthread_create(&c2, &attr, consume, (void*)t[3]);

  // Wait for all threads to complete
  pthread_join(p1, 0);
  pthread_join(p2, 0);
  pthread_join(c1, 0);
  pthread_join(c2, 0);

  // Clean up and exit
  pthread_attr_destroy(&attr);
  pthread_mutex_destroy(&bufMutex);
  pthread_cond_destroy(&bufEmptyCv);
  pthread_cond_destroy(&bufFullCv);
  pthread_exit(0);
}

