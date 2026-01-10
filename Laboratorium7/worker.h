#ifndef WORKER_H
#define WORKER_H

#include <semaphore.h>

void worker_loop(char *shm_ptr, sem_t *sem_server, sem_t *sem_worker);

#endif
