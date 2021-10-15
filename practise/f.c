#include<stdio.h>
#include<unistd.h>
#include<unwind.h>
#include  <sys/types.h>

int main()
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        // exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        printf("Hello from the child process!\n");
        // _exit(EXIT_SUCCESS);
    }
    else {
        int status;
        (void)waitpid(pid, &status, 0);
    }
    // return EXIT_SUCCESS;
    return 0;
}