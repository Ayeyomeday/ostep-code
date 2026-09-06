#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {

    int x = 100;
    int rc = fork();

    if (rc < 0) {
        printf("failed to fork\n");
    } else if (rc == 0) {
        x = 101;
        printf("Child process x-value: %d\n", x);
    } else {
        x = 102;
        printf("Parent process x-value: %d\n", x);
    }
    return 0;
}
