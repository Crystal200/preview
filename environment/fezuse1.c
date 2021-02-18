#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

char MSG_TRY[] = "try anain!\n";
char MSG_TMOUT[] = "time out!\n";

int main() {
	char buffer[10];
	int len;
	int fd;
	int i;
	fd = open ("/dev/tty", O_RDONLY | O_NONBLOCK);

	for (i = 0; i < 5; i++) { 
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
	}
	if (i == 5) {
		write(STDOUT_FILENO, MSG_TMOUT, strlen(MSG_TMOUT));
	} else {
		write(STDOUT_FILENO, buffer, len);
	}
	return 0;
}

