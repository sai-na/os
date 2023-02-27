#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main() {
    int fd;
    char buf[BUF_SIZE];
    ssize_t nread;

    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        exit(1);
    }

    while ((nread = read(fd, buf, BUF_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, nread) != nread) {
            perror("write failed");
            exit(1);
        }
    }

    if (nread == -1) {
        perror("read failed");
        exit(1);
    }

    if (close(fd) == -1) {
        perror("close failed");
        exit(1);
    }

    return 0;
}
