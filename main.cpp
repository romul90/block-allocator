#include <iostream>
#include <ballocator.h>
#include <list>

int main()
{
    size_t block_size = 48;
    uint8_t block_alignment = 8;
    size_t total_size = 480;

    char* small_buf = (char*)malloc(total_size);

    //list for saving allocations pointers
    std::list<void*> _allocs;

    BlockAllocator BAllocator(block_size, block_alignment, total_size, small_buf);

    //Test 1 allocating

    for (;;)
    {
        void* alloc = BAllocator.allocate();

        if(!alloc)
            break;
        _allocs.push_back(alloc);


    }

    assert(BAllocator.getMaxBlocks() <= total_size  / block_size);
    assert(BAllocator.getUsedMemory() <= total_size);
    assert(BAllocator.getNumAllocations() == _allocs.size());
    std::cout << "Test 1 passed" << std::endl;

    //Test 2 deallocating
    for (std::list<void*>::iterator it = _allocs.begin(); it != _allocs.end(); it++)
    {
      BAllocator.deallocate(*it);
    }

    assert(BAllocator.getUsedMemory() == 0);
    assert(BAllocator.getNumAllocations() == 0);
    std::cout << "Test 2 passed" << std::endl;

    block_size = 1024;
    block_alignment = 8;
    total_size = 1024 * 1024;

    char* big_buf = (char*)malloc(total_size);

    _allocs.clear();

    BlockAllocator BAllocator2(block_size, block_alignment, total_size, big_buf);

    //Test 3 allocating
    for (;;)
    {
        void* alloc = BAllocator2.allocate();

        if(!alloc)
            break;
        _allocs.push_back(alloc);


    }

    assert(BAllocator2.getMaxBlocks() <= total_size  / block_size);
    assert(BAllocator2.getUsedMemory() <= total_size);
    assert(BAllocator2.getNumAllocations() == _allocs.size());
    std::cout << "Test 3 passed" << std::endl;

    //Test 4 deallocating
    for (std::list<void*>::iterator it = _allocs.begin(); it != _allocs.end(); it++)
    {
      BAllocator2.deallocate(*it);
    }

    assert(BAllocator2.getUsedMemory() == 0);
    assert(BAllocator2.getNumAllocations() == 0);
    std::cout << "Test 4 passed" << std::endl;

    _allocs.clear();
    free(small_buf);
    free(big_buf);

    return 0;
}
