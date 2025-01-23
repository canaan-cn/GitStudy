// source/PramCheck.c
#include "ProcessCopy.h"

void check_arguments(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <source> <dest> <process_num>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int pronum = atoi(argv[3]);
    if (pronum <= 0 || pronum > 100) {
        fprintf(stderr, "Process number must be 0 < N <= 100\n");
        exit(EXIT_FAILURE);
    }
}
