#include "common.hpp"

/**
Thread id=139871780583168
Message id: 0
Severity: TRACE
File: /jphome/jp/ccjp/mb_ccjp/bb/gadjmemdb/v81_0_S2P230/crsesmem/src/SessionBasedGuidingExpiration.cpp
Function: SessionBasedGuidingExpiration::popSession
Line: 389
Time: Mon Sep 05 23:59:21

Message text: No session to pop from timeslot=243

#LINE:PATH_TO_FILE (FUNCTION)
DATE n TIME|SEVERITY| Message

#23:src/main.cpp (main)
Thu Sep-08 12:07.21.062843|TRACE| value of i: 6
 */

char *get_time_stamp()
{
    char stamp[50];
    struct timeval tv;
    static char _gtime[50];
    gettimeofday(&tv, NULL);
    time_t temp = tv.tv_sec;
    //strftime(stamp, 50, "%p %a %b-%d %H:%M.%S", localtime(&temp));
    strftime(stamp, 50, "%a %b-%d %H:%M.%S", localtime(&temp));
    sprintf(_gtime, "%s.%06ld", stamp, tv.tv_usec);
    return _gtime;
}
