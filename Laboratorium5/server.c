#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

void server_loop(int write_fd, int read_fd)
{
	char str[50];
	char str2[50];

	while(1)
	{
		printf("Wpisz tekst: ");
		scanf("%s", str);

		if(strcmp(str, "exit") == 0)
		{
			write(write_fd, str, strlen(str + 1));
			return ;
		}

		write(write_fd, str, strlen(str) + 1);

		read(read_fd, str2, sizeof(str2));
		printf("SERVER: Odebarane od worker: %s\n", str2);
	}
}
