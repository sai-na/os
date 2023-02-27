#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    DIR *dirp;
    struct dirent *dp;

    dirp = opendir(".");
    if (dirp == NULL) {
        perror("opendir failed");
        exit(1);
    }

    while ((dp = readdir(dirp)) != NULL) {
        printf("%s\n", dp->d_name);
    }

    closedir(dirp);
    return 0;
}
