#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
/*
stat 参数解释 ：
  第一个参数表示目标文件的路径   第二个参数表示的是输入参数,用来保存返回的文件的信息的结果
*/
int main() {
	struct stat st;
	int r = stat("test", &st);
	if (r) {
		perror("stat");
		return -1;
	}
	printf("st_dev = %d\n", st.st_dev);
	printf("st_ino = %llu\n", st.st_ino);
	printf("st_mode = %d\n", st.st_mode);
	printf("st_nlink = %d\n", st.st_nlink);
	printf("st_uid = %d\n", st.st_uid);
	printf("st_gid = %d\n", st.st_gid);
//	printf("st_rdev = %ld", st.st_rdev);
	printf("st_size = %lld", st.st_size);
//	printf("st_blksize = %ld", st.st_blksize);
//	printf("st_blocks = %ld", st.st_blocks);
	printf("st_atime = %ld\n", st.st_atime);
	printf("st_mtime = %ld\n", st.st_mtime);
	printf("st_ctime = %ld\n", st.st_ctime);

//stat如何获取文件信息
	//stat很容易从inode结构体中获取.比如st_mode字段源于inode的i_mode字段
	//作为用户态程序，无法直接读取磁盘，导致我们没有办法去解析磁盘数据。linux并不直接提供操作磁盘的办法 ，但是Linux提供了一些接口供使用，例如stat函数.
	

}
