#ifndef SERVER_H
#define SERVER_H

#include <semaphore.h>

void server_loop(char *shm_ptr, sem_t *sem_server, sem_t *sem_worker);

#endif
