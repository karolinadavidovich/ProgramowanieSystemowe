#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
        char str[50];
	int fd[2];
	char str2[50];
	int fd2[2];

	pipe(fd);
	pipe(fd2);
	printf("Wpisz tekst: ");
	scanf("%s", str);

	pid_t pid = fork();

	if (pid == 0)
	{
		close(fd[1]);
		close(fd2[0]);
		read(fd[0], str2, sizeof(str2));
		close(fd[0]);
		str2[0] = 'X';
		write(fd2[1], str2, strlen(str2) + 1);
		close(fd2[1]);
	}
	else
	{
		close(fd[0]);
		close(fd2[1]);
		write(fd[1], str, strlen(str) + 1);
		close(fd[1]);

		read(fd2[0], str2, sizeof(str2));
		close(fd2[0]);
		printf("Od dziecka: %s\n", str2);
	}

	return 0;
}
