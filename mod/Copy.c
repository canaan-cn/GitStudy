// mod/Copy.c

/* Author: tusen
  * email：jnl@outlook.kr
  * Country：China
  */
#include "ProcessCopy.h"

void copy_block(const char *src, const char *dest, off_t offset, size_t block_size) {
    int src_fd = open(src, O_RDONLY);
    int dest_fd = open(dest, O_WRONLY | O_CREAT, 0644);
    
    char buffer[4096];
    size_t remaining = block_size;
    
    lseek(src_fd, offset, SEEK_SET);
    lseek(dest_fd, offset, SEEK_SET);

    while (remaining > 0) {
        size_t read_size = remaining > sizeof(buffer) ? sizeof(buffer) : remaining;
        ssize_t bytes_read = read(src_fd, buffer, read_size);
        
        if (bytes_read <= 0) break;
        
        write(dest_fd, buffer, bytes_read);
        remaining -= bytes_read;
    }

    close(src_fd);
    close(dest_fd);
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Copy process usage: copy <src> <dest> <offset> <size>\n");
        return EXIT_FAILURE;
    }
    
    off_t offset = atol(argv[3]);
    size_t size = atol(argv[4]);
    
    copy_block(argv[1], argv[2], offset, size);
    return EXIT_SUCCESS;
}
