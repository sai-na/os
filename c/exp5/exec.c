#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"/bin/ls", "-l", NULL};
    execv(args[0], args);
    perror("execv failed");
    exit(1);
}
