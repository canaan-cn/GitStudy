// include/ProcessCopy.h
#ifndef PROCESS_COPY_H
#define PROCESS_COPY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct {
    off_t offset;
    size_t block_size;
} BlockInfo;

// 函数声明
void check_arguments(int argc, char **argv);
BlockInfo calculate_blocks(const char *filename, int pronum);
void create_processes(int pronum, const char *src, const char *dest, BlockInfo *blocks);
void wait_children(int pronum);
void copy_block(const char *src, const char *dest, off_t offset, size_t block_size);

#endif
