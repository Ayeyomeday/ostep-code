#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {

    int rc = fork();

    if (rc < 0) {
        printf("failed to fork\n");
    } else if (rc == 0) {
        close(STDOUT_FILENO);
        printf("hello\n");
    } else {
        printf("goodbye\n");
    }
    return 0;
}

/*********************************************
   Your name: Ayomide Oludairo
   Question 7: 

   Performing close(STDOUT_FILENO); prevents
   the child from being able to print to the
   terminal.
*********************************************/

