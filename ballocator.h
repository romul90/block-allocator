#ifndef BALLOCATOR_H
#define BALLOCATOR_H


#include <stdint.h>
#include <assert.h>
#include <iostream>


class BlockAllocator
{
public:
    BlockAllocator(size_t blockSize, uint8_t blockAlignment, size_t size, void* mem);
    ~BlockAllocator();

    void* allocate();
    void deallocate(void* p);

    size_t getMaxBlocks() const { return _max_blocks; }
    size_t getUsedMemory() const { return _used_memory; }
    size_t getNumAllocations() const { return _num_allocations; }

   //possible block limit:
   // static const uint32_t MIN_BLOCK_SIZE = 4 * 1024;

private:

    BlockAllocator(const BlockAllocator&);

    //To avoid copying
    BlockAllocator& operator= (const BlockAllocator);

    size_t _block_size;
    uint32_t _block_alignment;
    size_t _used_memory;
    size_t _num_allocations;
    size_t _max_blocks;

    //list for saving free chunks of memory
    void** _free_list;


};

#endif // BALLOCATOR_H
