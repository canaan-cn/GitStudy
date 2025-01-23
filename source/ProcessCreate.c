// source/ProcessCreate.c

 /* Author: tusen
  * email：jnl@outlook.kr
  * Country：China
  */
#include "ProcessCopy.h"

void create_processes(int pronum, const char *src, const char *dest, BlockInfo *blocks) {
    for (int i = 0; i < pronum; i++) {
        pid_t pid = fork();
        if (pid == 0) { // Child process
            char offset_str[32], size_str[32];
            snprintf(offset_str, sizeof(offset_str), "%ld", blocks[i].offset);
            snprintf(size_str, sizeof(size_str), "%zu", blocks[i].block_size);
            
            execl("mod/copy", "copy", src, dest, offset_str, size_str, NULL);
            perror("execl");
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }
}
