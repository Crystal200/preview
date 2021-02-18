#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

char MSG_TRY[] = "try anain!\n";

int main() {
	char buffer[10];
	int len;
	int fd;

	fd = open ("/dev/tty", O_RDONLY | O_NONBLOCK);

	while(1) {
		len = read(fd, buffer, 10);
		if (len < 0) {
		//表示数据没有到达
			if(errno == EAGAIN) {
				write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
				sleep(1);
			} else {
				perror("read");
				exit(1);
			} 
				}else {
					break;
			} 
	
		write(STDOUT_FILENO, buffer, len);
		return 0;
	}
}

