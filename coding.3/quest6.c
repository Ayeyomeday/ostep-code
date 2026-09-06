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
        int rc_wait = waitpid(rc, NULL, 0);
        printf("hello\n");
        printf("parent of %d (rc_wait:%d) (pid:%d)\n", 
            rc, rc_wait, (int) getpid());
    } else {
        printf("goodbye\n");
        int rc_wait = waitpid(rc, NULL, 0);
        printf("parent of %d (rc_wait:%d) (pid:%d)\n", 
            rc, rc_wait, (int) getpid());
    }
    return 0;
}

/*********************************************
   Your name: Ayomide Oludairo
   Question 6: 

   waitpid() is useful for when you want to
   wait for a specific child to finish its 
   running process.
*********************************************/
