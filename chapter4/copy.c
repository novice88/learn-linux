#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <utils.h>
#include <unistd.h>

#ifndef BUF_SIZE
#define BUF_SIZE  1024
#endif

int main(int argc, char* argv[]) {
    int input_fd,outputFd,open_flag;
    mode_t file_perms;
    ssize_t num_read;
    if (argc != 3 ){
        fprintf(stderr,"usage: copy src target");
        exit(1);
    }


    return 0;
}