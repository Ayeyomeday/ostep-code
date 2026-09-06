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
        execl("/bin/ls", "ls", NULL);
    } else {
        printf("Parent\n");
    }

    return 0;
}

/*********************************************
   Your name: Ayomide Oludairo
   Question 4: 

    The different versions of exec() allow for
    variability in inputing paths and arguments.
*********************************************/
