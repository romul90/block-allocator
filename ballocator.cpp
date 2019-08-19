#include "ballocator.h"

BlockAllocator::BlockAllocator(size_t blockSize, uint8_t blockAlignment, size_t size, void* mem)
{
    //assert(blockSize >= MIN_BLOCK_SIZE);
    assert(blockSize >= sizeof (void*));
    _block_size = blockSize;
    _block_alignment = blockAlignment;
    _used_memory = 0;
    _num_allocations = 0;
    _max_blocks = 0;

    uint8_t adjustment = reinterpret_cast<uintptr_t>(mem)& static_cast<uintptr_t>(blockAlignment - 1);

    //if already adjusted
    if (adjustment == blockAlignment)
        adjustment = 0;

    //free list creating
    _free_list = (void**)((void*)(reinterpret_cast<uintptr_t>(mem) + adjustment));
    size_t numBlocks = (size - adjustment) / blockSize;
    _max_blocks = numBlocks;
    void** p = _free_list;

    //Initializing free blocks list
    for(size_t i = 0; i < numBlocks - 1; i++)
    {
        *p = (void*)(reinterpret_cast<uintptr_t>(p) + blockSize);
        p = (void**) *p;

    }

    *p = nullptr;

}

BlockAllocator::~BlockAllocator()
{
    _free_list = nullptr;
}

void* BlockAllocator::allocate()
{
    if (_free_list == nullptr) return nullptr;
    void* p = _free_list;
    _free_list = (void**)(*_free_list);
    _used_memory += _block_size;
    _num_allocations++;
    return p;
}

void BlockAllocator::deallocate(void *p)
{
    assert(_num_allocations != 0 && _used_memory != 0);
    *((void**)p) = _free_list;
    _free_list = (void**)p;
    _used_memory -= _block_size;
    _num_allocations--;
}
