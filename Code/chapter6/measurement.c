#include "../common.h"

int 
main(int argc, char *argv[])
{
    // 获取系统调用之前的时间
    struct timeval old_tv;
    int err = gettimeofday(&old_tv, 0);
    if(err)
    {
        printf("Get time of day failed, errno: %d\n", err);
        exit(1);
    }
    printf("current microsecond: %ld\n", old_tv.tv_usec);

    // 系统调用：空read
    read(0, NULL, 0);
    printf("System call: read\n");

    // 系统调用之后的时间
    struct timeval new_tv;
    err = gettimeofday(&new_tv, 0);
    if(err)
    {
        printf("Get time of day failed, errno: %d\n", err);
        exit(1);
    }
    printf("current microsecond: %ld\n", new_tv.tv_usec);

    // 计算系统调用花费的时间
    printf("System call time measurement: %ld ms\n", new_tv.tv_usec-old_tv.tv_usec);
    return 0;
}