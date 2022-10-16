// #ifndef __PRATIK_HPP
// #define __PRATIK_HPP

#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
using namespace std;

#define KRESET  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

extern short ptr;

//if you want to turn off logging and just want to print simple print statement ucomment following line
// #define PRODUCTION_SERVER

#ifndef PRODUCTION_SERVER

    // for C language
    #define LogDebug(msg, ...)                           \
        fprintf(stdout, "#%d:%s (%s)\n", __LINE__, __FILE__,__FUNCTION__); \
        fprintf(stdout, "%s|%s|%s|%s|DEBUG| " msg " \n", get_time_stamp(),__DATE__,__TIME__,__TIMESTAMP__,##__VA_ARGS__);

    // for C++ language
    #define Log0                                                  \
        if (ptr <= 0)                                            \
        std::cout << "\n#" << __LINE__ << ":" << __FILE__ << " (" << __FUNCTION__ <<")\n" \
                << get_time_stamp() << KWHT "|DEBUG|" KRESET << " "
    #define Log1                                                  \
        if (ptr <= 1)                                            \
        std::cout << "\n#" << __LINE__ << ":" << __FILE__ << " (" << __FUNCTION__ << ")\n" \
                << get_time_stamp() << KGRN "|TRACE|" KRESET << " "
    #define Log2                                                  \
        if (ptr <= 2)                                            \
        std::cout << "\n#" << __LINE__ << ":" << __FILE__ << " (" << __FUNCTION__ << ")\n" \
                << get_time_stamp() << KBLU "|INFO|" KRESET << " "
    #define Log3                                                  \
        if (ptr <= 3)                                            \
        std::cout << "\n#" << __LINE__ << ":" << __FILE__ << " (" << __FUNCTION__ << ")\n" \
                << get_time_stamp() << KYEL "|WARNING|" KRESET << " "
    #define Log4                                                  \
        if (ptr <= 4)                                            \
        std::cout << "\n#" << __LINE__ << ":" << __FILE__ << " (" << __FUNCTION__ << ")\n" \
                << get_time_stamp() << KRED "|ERROR|" KRESET << " "
    #define Log5                                                  \
        if (ptr <= 5)                                            \
        std::cout << "\n#" << __LINE__ << ":" << __FILE__ << " (" << __FUNCTION__ << ")\n" \
                << get_time_stamp() << KMAG "|FATAL|" KRESET << " "
#else
    #define LogDebug(msg, ...) \
        fprintf(stdout, msg "\n", ##__VA_ARGS__);

    #define Log0\
    if (ptr >= 0)       \
            std::cout \
        << "\n"
    
    #define Log1\
    if (ptr >= 1)       \
            std::cout \
        << "\n"

#endif //PRODUCTION_SERVER

char* get_time_stamp();

//#endif