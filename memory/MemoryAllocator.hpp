#pragma once

#include <Windows.h>

/**
 * Class for allocate memory
 */
class MemoryAllocator
{
public:
    /**
     * Allocate memory
     */
    template<typename T>
    static T* allocate(u_int size)
    {
        return (T*)HeapAlloc(GetProcessHeap(), HEAP_NO_SERIALIZE, size);
    }

    /**
     * Free allocate memory
     */
    template<typename T>
    static bool free(T* memoryPointer)
    {
        return HeapFree(GetProcessHeap(), HEAP_NO_SERIALIZE, (LPVOID)memoryPointer);
    }
};