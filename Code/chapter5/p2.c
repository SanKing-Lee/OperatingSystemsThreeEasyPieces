#include "../common.h"

int
main(int argc, char *argv[])
{
    printf("hello world! (pid:%d)\n", getpid());
    // fork new process
    int rc = fork();
    int rc1 = fork();
    // fork failed
    if (rc < 0)
    {
        fprintf(stderr, "fork failed (pid:%d)\n", getpid());
        exit(1);
    }
    // child process
    else if (rc == 0)
    {
        printf("hello, I am child (pid:%d)\n", (int)getpid());
    }
    // parent process
    else
    {
        // wait api
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, getpid());
    }
    // fork failed
    if (rc1 < 0)
    {
        fprintf(stderr, "fork failed (pid:%d)\n", getpid());
        exit(1);
    }
    // child process
    else if (rc1 == 0)
    {
        printf("hello, I am child (pid:%d)\n", (int)getpid());
    }
    // parent process
    else
    {
        // wait api
        int wc1 = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc1, wc1, getpid());
    }
    return 0;
    
}