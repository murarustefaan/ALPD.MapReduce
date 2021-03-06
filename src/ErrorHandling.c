/**
 * Function library used for handling error signals
 *
 * @author Stefan Muraru
 * @date 01.12.2017
 */

#include <signal.h>
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../defs/ErrorHandling.h"

/**
 * Signal handler to use for debugging purposes
 * @param sig The signal to handle
 */
void handler(int sig) {
    void *array[10];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 10);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}
