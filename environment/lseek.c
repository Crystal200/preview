#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int main() {
	int fd = open("test",O_RDONLY);
	if (fd < 0) {
		perror("open");
		return 1;
	}
	char buf[64] = {0};
	lseek(fd, 6, SEEK_SET);
	read(fd, buf, 64);
	printf("%s\n", buf);
	return 0;
}
