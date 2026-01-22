#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "worker.h"

extern int pipe_in[2];
extern int pipe_out[2];
extern pthread_mutex_t mutex;

void* worker_thread(void* arg) {
	char buf[100];

	while(1) {
		read(pipe_in[0], buf, sizeof(buf));

		pthread_mutex_lock(&mutex);

		if (strcmp(buf, "exit") == 0) {
			write(pipe_out[1], buf, strlen(buf)+1);
			pthread_mutex_unlock(&mutex);
			break;
		}

		buf[0] = 'X';

		write(pipe_out[1], buf, strlen(buf)+1);

		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}
