#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {

    int file = open("random.txt", O_WRONLY | O_CREAT | O_APPEND);
    int rc = fork();

    if (rc < 0) {
        printf("failed to fork\n");
    } else if (rc == 0) {
        write(file, "I am the Child\n", 15);
    } else {
        write(file, "I am the Parent\n", 16);
    }

    close(file);
    return 0;
}

/*********************************************
   Your name: Ayomide Oludairo
   Question 2: 

   Both the child and parent write into the
   created file. The OS scheduler decides 
   which process gets to run first.
*********************************************/
