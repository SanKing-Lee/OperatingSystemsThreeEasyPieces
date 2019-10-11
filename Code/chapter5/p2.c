#include "../common.h"

int getvalue();

int
main(int argc, char *argv[])
{
    printf("hello world! (pid:%d)\n", getpid());
    // fork new process
    int rc1 = getvalue();
    int *a = (int*)malloc(sizeof(int));
    *a = 8;
    printf("hello world! (pid:%d)\n", getpid());
    int rc = fork();
    // fork failed
    if (rc < 0)
    {
        fprintf(stderr, "fork failed (pid:%d)\n", getpid());
        exit(1);
    }
    // child process
    else if (rc == 0)
    {
        rc1 = 234;
        *a = 20;
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        printf("rc1: %d\n", rc1);
        printf("a: %d\n", *a);
    }
    // parent process
    else
    {
        // wait api
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, getpid());
        printf("rc1: %d\n", rc1);
        printf("a: %d\n", *a);
    }
    return 0;
}

int getvalue()
{
    return 256;
}