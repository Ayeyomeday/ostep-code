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

/*********************************************
   Your name: Ayomide Oludairo
   Question 1: 

   In the child process x becomes 101. In the
   parent process x becomes 102. Since I
   created a fork, each process has its own
   copy of x, so changing x in one process
   has no effect on the x in the other.
*********************************************/