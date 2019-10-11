#include "../common.h"

int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
    }
    else if(rc == 0)
    {
        close(STDOUT_FILENO);
        open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC);
        char *myargs[3];
        myargs[0] = "wc";
        myargs[1] = "p4.c";
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
    }
    else {
        int wc = wait(NULL);
    }
    return 0;
}