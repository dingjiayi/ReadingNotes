# 1. 文件访问：系统调用 #
## 1.1 打开（创建）、读、写、定位、删除文件 ##
### 1.1.1 打开（创建）文件 open ###
#### (1) open ####
1. 头文件
    	#include <fcntl.h>   /*fcntl -- file control*/
    	#include <sys/types.h>
    	#include <sys/stat.h>
2. 声明
	int open(const char *path, int oflags);
	int open(const char *path, int oflags, mode_t mode);
3. 说明：
3.1 oflags 通常使用 O_RDONLY, O_WRONLY, O_RDWR
3.2 权限设置：S_IRUSR, S_IWGRP, S_IXOTH, ...
3.3 权限设置需要注意系统的unmask变量
### 1.2.1 写入文件 ###
#### （1） write ####
1. 头文件
	#include <unistd.h>
2. 声明
	`size_t write(int fildes, const void *buf, size_t nbytes);`
3. 说明：
	返回值可能比要求写入的小，这并不一定是个错误。
### 1.3.1 读取文件 ###
#### （1） read ####
1. 头文件
	`#include <unistd.h>`
2. 声明
	size_t read(int fildes, void *buf, size_t nbytes)
### 1.4.1 关闭文件 ###
1. 头文件
	`#include <unistd.h>`
2. 声明
	int close(int fildes);
3. 说明
	成果返回0， 失败返回-1
#### 1.5.1 大杂烩调用 ioctl ####
1. 头文件
	`#include <unsitd.h>`
2. 声明
	`int ioctl(int fildes, int cmd, ...)`
## 1.2 其他文件管理有关系统调用 ##
### 1.2.1 lseek 系统调用 ###
1. 函数功能：对文件描述符 fildes的读写指针进行设置。
2. 声明
    	#include <unistd.h>
    	#include <sys/types.h>   //包含off_t的定义
    	
    	off_t lseek(int fildes, off_t offset, int whence)

3. whence参数取下列值之一
    	SEEK_SET: offset是一个绝对值
    	SEEK_CUR: offset是相对于当前位置的一个相对位置。
    	SEEK_END: offset是相对于文件尾的一个相对位置。
4. 返回：
 	成功：文件头到文件指针别设置处的字节偏移值，失败：返回-1

### 1.2.2 fstat、stat和lstat系统调用 ###
1. 声明
    	#include <unistd.h>
    	#include <sys/types.h>
    	#include <sys/stat.h>
    	
    	int ftat(int fildes, struct stat *buf)
    	int stat(const char *path, struck stat *buf)
    	int lstat(const char *paht, struct stat *buf)

2. stat 成员结构
    	st_mode 			文件权限和文件类型信息
    	st_ino 				与该文件关联的inode
    	st_dev 				保存文件的设备
    	st_uid 				文件属主的UID号
    	st_gid 				文件属主的GID号
    	st_atime 			文件上一次被访问的时间


3. stat()和lstat()的区别就是：当文件是一个符号链接时，lstat返回的是符号链接本身的信息，stat返回的是该链接指向的文件的信息。
4. stat.st_mode
	（1）掩码：S_IFMT：文件类型，S_IRWXU：属主的读/写/执行权限，S_IRWXG：属组的读/写/执行权限，S_IRWXO:其他用户的读/写/执行权限。
	（2）确定文件类型的宏定义（对经过掩码处理的模式标识和相应的设备类型标识进行比较）：S_ISDIR 测试是否是目录，S_ISLINK 测试是否是符号链接。
### 1.2.3 dup和dup2 ###
1. 声明
	#include <unistd.h>
	int dup(int fd)
	int dup2(int old_fd, int new_fd)
2. 返回
	成果：返回新的文件描述符，失败：-1
3. 说明：
	dup：返回新文件描述符一定是当前可用文件描述符中的最小整数。
	dup2:如果new_fd已经打开，则先关闭。如果old_fd == new_fd，则dup2直接回new_fd，不去关闭new_fd

