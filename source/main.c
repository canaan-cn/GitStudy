// source/main.c
#include "ProcessCopy.h"

int main(int argc, char **argv) {
    check_arguments(argc, argv);
    
    int pronum = atoi(argv[3]);
    BlockInfo *blocks = malloc(pronum * sizeof(BlockInfo));
    
    // 计算分块信息
    BlockInfo bi = calculate_blocks(argv[1], pronum);
    for (int i = 0; i < pronum; i++) {
        blocks[i].offset = i * bi.block_size;
        blocks[i].block_size = bi.block_size;
    }
    // 最后一个块处理余数
    blocks[pronum-1].block_size += bi.offset; 

    create_processes(pronum, argv[1], argv[2], blocks);
    wait_children(pronum);
    
    free(blocks);
    return 0;
}
