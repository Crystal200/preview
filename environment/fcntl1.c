#include <unistd.h>
#include <sys/tyes.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

char MSG_TRY[] = "try again!\n";

int main() {
	char buffer[10];
	int len;
	int fd;

	int flags = fcntl(STDIN_FILENO, F_GETFL);
	if (flags == -1) {
		perror("fcntl get");
		exit(1);
	}

	flags |= O_NONBLOCK;

	if (fcntl(STDIN_FILENO, F_SETFL, flags) == -1) {
		perror("fcntl set");
		exit(1);
	}
	
	while(1) {
		len = read(STDIN_FILENO, buffer, 10);
		if (len < 0) {
			if(errno == EAGAIN) {
				write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
				sleep(1); //让出cpu 避免cpu长时间空转
			} else {
			 perror("read");
			 exit(1);
			}
		} else {
		 	break;
		} 
	}
	write(STDOUT_FILENO, buffer, len);
	return 0;
}

