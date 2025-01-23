// source/BlockCur.c
#include "ProcessCopy.h"

BlockInfo calculate_blocks(const char *filename, int pronum) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open source file");
        exit(EXIT_FAILURE);
    }
    
    struct stat st;
    fstat(fd, &st);
    off_t file_size = st.st_size;
    
    BlockInfo bi;
    bi.block_size = file_size / pronum;
    bi.offset = 0;
    
    close(fd);
    return bi;
}
