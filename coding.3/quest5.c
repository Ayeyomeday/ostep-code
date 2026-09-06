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
        int rc_wait = wait(NULL);
        printf("hello\n");
        printf("parent of %d (rc_wait:%d) (pid:%d)\n", 
            rc, rc_wait, (int) getpid());
    } else {
        printf("goodbye\n");
        int rc_wait = wait(NULL);
        printf("parent of %d (rc_wait:%d) (pid:%d)\n", 
            rc, rc_wait, (int) getpid());
    }
    return 0;
}

/*********************************************
   Your name: Ayomide Oludairo
   Question 5: 

   When wait is used in the child, it returns 
   -1. This could be because the child doesn't
   have any child processes to wait for, so the
   call fails. Otherwise, wait returns the PID
   of the first child that finishes.
*********************************************/
