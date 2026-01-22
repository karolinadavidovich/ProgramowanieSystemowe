#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include "server.h"
#include "worker.h"

int pipe_in[2];
int pipe_out[2];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void start_server() {
	int server_fd, client_fd;
	struct sockaddr_in addr;
	char buf[100];

	pipe(pipe_in);
	pipe(pipe_out);

	pthread_t t1, t2;
	pthread_create(&t1, NULL, worker_thread, NULL);
	pthread_create(&t2, NULL, worker_thread, NULL);

	server_fd = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_family= AF_INET;
	addr.sin_port = htons(1234);
	addr.sin_addr.s_addr = INADDR_ANY;

	bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
	listen(server_fd, 1);

	printf("Server dziala na porcie 1234\n");

	client_fd = accept(server_fd, NULL, NULL);

	while(1) {
		read(client_fd, buf, sizeof(buf));
		write(pipe_in[1], buf, strlen(buf)+1);

		read(pipe_out[0], buf, sizeof(buf));
		write(client_fd, buf, strlen(buf)+1);

		if (strcmp(buf, "exit") == 0)
			break;
	}

	close(client_fd);
	close(server_fd);
}



