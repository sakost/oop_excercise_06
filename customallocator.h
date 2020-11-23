//
// Created by sakost on 23.11.2020.
//

#ifndef OOP_EXCERCISE_06_CUSTOMALLOCATOR_H
#define OOP_EXCERCISE_06_CUSTOMALLOCATOR_H

#include "customlist.h"

#include <cinttypes>
#include <cstdlib>

using Byte = unsigned char;

template <typename T>
struct CustomAllocator {
    CustomAllocator(int32_t size, int32_t count){
        _used_blocks = (Byte *) malloc(size * count);

        for(int32_t i = 0; i < count; ++i) {
            void *ptr = _used_blocks + i * size;
            _free_blocks.push_back(ptr);
        }
    }

    void* allocate(){
        if(!_free_blocks.empty()){
            auto front = _free_blocks.front();
            return front;
        }
        throw std::bad_alloc();
    }

    void deallocate(void *ptr){
        _free_blocks.push_back(ptr);
    }

    bool empty(){
        return _free_blocks.empty();
    }

    int32_t size(){
        return _free_blocks.size();
    }

    ~CustomAllocator(){
        while(!_free_blocks.empty()){
            _free_blocks.pop_back();
        }

        free(_used_blocks);
    }

    Byte *_used_blocks;
    CustomList<void *> _free_blocks;
};


#endif //OOP_EXCERCISE_06_CUSTOMALLOCATOR_H
