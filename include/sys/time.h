#ifndef _SYS_TIME_H
#define _SYS_TIME_H

#include <sys/types.h>

typedef long suseconds_t;

struct timeval {
    time_t      tv_sec;     /* seconds */
    suseconds_t tv_usec;    /* microseconds */
};

struct timezone {
    int tz_minuteswest;     /* minutes west of Greenwich */
    int tz_dsttime;         /* type of DST correction */
};

// Note: gettimeofday is already declared in unistd.h with different signature
// int gettimeofday(void* tv_out, void* tz_ignored);
int settimeofday(const struct timeval *tv, const struct timezone *tz);

#endif /* _SYS_TIME_H */
