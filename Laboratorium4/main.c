#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
        char str[50];
	int fd[2];
	char str2[50];

	pipe(fd);
	printf("Wpisz tekst: ");
	scanf("%s", str);

	pid_t pid = fork();

	if (pid == 0)
	{
		close(fd[1]);
		read(fd[0], str2, sizeof(str2));

		str2[0] = 'X';
		printf("%s\n", str2);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		write(fd[1], str, strlen(str) + 1);
		close(fd[1]);

		wait(NULL);
	}

	return 0;
}

