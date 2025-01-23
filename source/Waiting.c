// source/Waiting.c
#include "ProcessCopy.h"

void wait_children(int pronum) {
    int status;
    for (int i = 0; i < pronum; i++) {
        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Child process exited abnormally\n");
        }
    }
}
