#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Before exit\n");
    exit(0);
    printf("After exit\n"); // This code will never be executed.
}
