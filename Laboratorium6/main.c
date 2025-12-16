#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "server.h"
#include "worker.h"

#define FIFO1 "fifo_server_to_worker"
#define FIFO2 "fifo_worker_to_server"

int main(int argc, char *argv[]) {
		if (argc < 2) {
		printf("Uzycie: %s  server | worker\n", argv[0]);
		return 1;
	}

	if (strcmp(argv[1], "server") == 0) {

		mkfifo(FIFO1, 0666);
		mkfifo(FIFO2, 0666);

		printf("SERVER: Otwieram kolejki...\n");

		int write_fd = open(FIFO1, O_WRONLY);
		int read_fd = open(FIFO2, O_RDONLY);

		printf("SERVER: Kolejki otwarte. Start server_loop...\n");

		server_loop(write_fd, read_fd);

		close(write_fd);
		close(read_fd);

		unlink(FIFO1);
		unlink(FIFO2);

		printf("SERVER: Zakonczono i usunieto kolejki.\n");
		fflush(stdout);
	}
	else if (strcmp(argv[1], "worker") == 0) {

		printf("WORKER: Otwieram kolejki...\n");

		int read_fd = open(FIFO1, O_RDONLY);
		int write_fd = open(FIFO2, O_WRONLY);

		printf("WORKER: Kolejki otwarte. Start worker_loop...\n");

		worker_loop(read_fd, write_fd);

		close(read_fd);
		close(write_fd);

		printf("WORKER: Zakonczono\n");
	}
	else {
		printf("Nieznany tryb.");
		return 1;
	}

	return 0;
}
