#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {

    int fd[2];

    if (pipe(fd) < 0) {
        printf("Pipe failed\n");
        exit(1);
    }

    int rc = fork();
    if (rc < 0) {
        printf("failed to fork\n");
    }

    if (rc == 0) {
        // Send stdout into the pipe
        dup2(fd[1], STDOUT_FILENO);

        // Close unused file descriptors
        close(fd[0]);
        close(fd[1]);

        // Write something to stdout
        printf("Hello from child 1!\n");

        exit(0);
    }

    //second child
    int rc2 = fork();

    if (rc2 < 0) {
        printf("failed to fork\n");
        exit(1);
    }

    if (rc2 == 0) {
        // Get stdin from the pipe
        dup2(fd[0], STDIN_FILENO);

        // Close unused file descriptors
        close(fd[0]);
        close(fd[1]);

        // Read whatever Child 1 sent through the pipe
        char buffer[100];
        int n = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);

        if (n > 0) {
            buffer[n] = '\0';
            printf("Child 2 received: %s", buffer);
        }
        exit(0);
    }

    // Parent doesn't need either end of the pipe
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}