#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
	int sock;
	struct sockaddr_in addr;
	char buf[100];

	sock = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(sock, (struct sockaddr*)&addr, sizeof(addr));

	while(1) {
		printf("Client: ");
		scanf("%s", buf);

		write(sock, buf, strlen(buf)+1);
		read(sock, buf, sizeof(buf));

		printf("Server odp: %s\n", buf);

		if (strcmp(buf, "exit") == 0)
			break;
	}
	close(sock);
	return 0;
}
