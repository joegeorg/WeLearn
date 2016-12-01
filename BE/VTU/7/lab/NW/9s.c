#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int sockfd, newfd, yes = 1;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	
	struct sockaddr_in saddr, taddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(6980);
	saddr.sin_addr.s_addr = INADDR_ANY;
	memset(&(saddr.sin_zero), '0', 8);

	bind(sockfd, (struct sockaddr *) &saddr, sizeof(struct sockaddr));
	listen(sockfd, 10);

	int sin_size = sizeof(struct sockaddr);
	newfd = accept(sockfd, (struct sockaddr *) &taddr, &sin_size);

	char filename[100], buffer[1 << 20];
	recv(newfd, filename, sizeof(filename), 0);

	int fd = open(filename, O_RDONLY);
	read(fd, buffer, sizeof(buffer));
	close(fd);

	send(newfd, buffer, sizeof(buffer), 0);

	close(newfd);
	close(sockfd);    
	return 0;
}

