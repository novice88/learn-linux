#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <utils.h>
#include <unistd.h>

#ifndef BUF_SIZE
#define BUF_SIZE  10240
#endif

char buf[BUF_SIZE];

int main(int argc, char* argv[]) {
    if (argc != 3 ){
        fprintf(stderr,"usage: copy src target\n");
        exit(1);
    }
    int  input_fd = open(argv[1],O_RDONLY);
    if (input_fd == -1){
        fprintf(stderr,"can not open file: %s\n",strerror(errno));
        exit(1);
    }
    mode_t perm = S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH;
    int open_flags = O_CREAT|O_WRONLY|O_TRUNC;
    int output_fd = open(argv[2],open_flags,perm);
    if (output_fd == -1){
        fprintf(stderr,"can not open file: %s\n",strerror(errno));
        exit(1);
    }
    ssize_t num_read;
    while ((num_read = read(input_fd,buf,BUF_SIZE)) > 0){
        if (write(output_fd,buf,num_read)  != num_read){
            fprintf(stderr,"can not write file: %s\n",strerror(errno));
            exit(1);
        }
    }
    close(input_fd);
    close(output_fd);
    return 0;
}