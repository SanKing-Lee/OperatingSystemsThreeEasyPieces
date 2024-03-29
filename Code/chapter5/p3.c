#include "../common.h"

int 
main(int argc, char *argv[])
{
    printf("hello world! (pid:%d)\n", getpid());
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed!\n");
        exit(1);
    }
    else if(rc == 0)
    {
        printf("hello, I am child (pid:%d)\n", getpid());
        char *myargs[3];
        myargs[0] = "wc";
        myargs[1] = "p3.c";
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("this shouldn't print out!\n");
    }
    else
    {
        int wc = wait(NULL);
        printf("hello, I am parent of %d(wc:%d) (pid:%d)\n",
            rc, wc, (int)getpid());
    }
    return 0;
    
}