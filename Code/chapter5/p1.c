#include "../common.h"

int 
main(int argc, char *argv[])
{
    // 输出当前进程id
    printf("hello world (pid:%d)\n", getpid());
    // 创建一个新进程
    int rc = fork();
    // 进程创建失败
    if (rc < 0)
    {
        fprintf(stderr, "fork failed!\n");
        exit(1);
    }
    // 子进程
    else if (rc == 0)
    {
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        // 创建“孙子”进程
        int rc1 = fork();
        // 进程创建失败
        if (rc1 < 0)
        {
            fprintf(stderr, "fork failed!\n");
            exit(1);
        }
        // 子进程
        else if (rc1 == 0)
        {
            printf("hello, I am child (pid:%d)\n", (int)getpid());
            printf("process (pid:%d) finished\n", getpid());
        }
        // 父进程
        else
        {
            printf("hello, I am parent of %d (pid:%d)\n", rc1, (int)getpid());
        }
        printf("process (pid:%d) finished\n", getpid());
    }
    // 父进程
    else
    {
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
    }
    // final code
    printf("process (pid:%d) finished\n", getpid());
    return 0;
}