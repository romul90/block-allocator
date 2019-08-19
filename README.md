# Block allocator
Custom block allocator test

The search for a solution for writing your own allocator ended with the choice of using the type of linked list with the preservation of pointers to the next free block. At the time of study and searching, I found the article of 2013 with an excerpt of the code. This article has been used **very heavily**.

https://www.gamedev.net/articles/programming/general-and-gameplay-programming/c-custom-memory-allocation-r3010/?page=2

Tests are implemented in main().

It is needed to:
- [ ] Optimize allocator for work with RTOS
- [ ] Create CMake-style package
- [ ] Add more Unit-tests (using Catch)

P.S. Before that, I had never completely touched allocators and embedded systems. I was engaged in C++ in conjunction with ROS - worked on the creating of the trajectory of robots, developed scripts for this, and also worked on the implementation of the direct and inverse positioning problem for the three-manipulator robot. I suspect that this allocator project can hardly be called fully or partially suitable for work, however, the search, study and creation of this project was an interesting time. Thanks.

Reference list:

https://habr.com/ru/post/274827/

http://www.cplusplus.com/reference/memory/allocator/

https://ru.cppreference.com/w/cpp/memory/allocator 

http://coderway.ru/cpp/dynamic-memory-alloc

https://blog.molecular-matters.com/2011/07/05/memory-system-part-1/

https://habr.com/ru/post/106294/

https://ru.cppreference.com/w/cpp/types/size_t
