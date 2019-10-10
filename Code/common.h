#ifndef _COMMON_H
#define _COMMON_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void 
Spin(int intervalSecond);

void
Spin(int intervalSecond)
{
    time_t currentTime, lastTime;
    lastTime = time((time_t *) 0);
    do{
        currentTime = time((time_t *) 0);
    }    while((unsigned)currentTime - (unsigned)lastTime < intervalSecond);
}

#endif