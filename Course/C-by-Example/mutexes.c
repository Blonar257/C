#include <stdio.h>
#include <threads.h>

typedef struct data {
  mtx_t mtx;
  int x;
} data;

int thread_func(void *arg) {
  data *d = (data *)arg;
  mtx_lock(&d->mtx);
  d->x = 2;
  mtx_unlock(&d->mtx);
  return 0;
}

int main() {
  data d;
  mtx_init(&d.mtx, mtx_plain);
  thrd_t thread_id;
  thrd_create(&thread_id, thread_func, (void *)&d);
  thrd_join(thread_id,
            NULL); // Wait for thread to return before continuing execution
  printf("x has safely been modified to %d\n", d.x);
  return 0;
}
