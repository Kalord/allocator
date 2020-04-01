#pragma once

#include "MemoryAllocator.hpp"

/**
 * This class is identity of the allocate memory
 */
template<typename T>
class Memory
{
private:
    /**
     * Memory allocated 
     */
    T* memory;
    /**
     * Counter of reference to allocated memory
     */
    inline static u_int counter = 0;
public:
    Memory(T* memory) : memory(memory)
    {
        Memory::counter++;
    }

    ~Memory()
    {
        Memory::counter--;
        if (!Memory::counter) MemoryAllocator::free(this->memory);
    }

    T* get()
    {
        return this->memory;
    }

    /**
     * Access to allocated memory
     */
    T* operator->()
    {
        return this->memory;
    }

    /**
     * Access to allocated memory as array    
     */
    T* operator[](u_int index)
    {
        return this->memory + index;
    }
};