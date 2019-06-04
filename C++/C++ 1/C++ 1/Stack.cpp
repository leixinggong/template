//
//  Stack.cpp
//  C++ 1
//
//  Created by glx on 2019/5/30.
//  Copyright © 2019 glx. All rights reserved.
//

#include "Stack.hpp"
#include <memory.h>

using namespace GL;

Stack::Stack(int size)
        :size(size),top(0),space(new int[size]{0})
{}

Stack::Stack(const GL::Stack &another)
{
    top = another.top;
    size = another.size;
    space = new int[size];
    memcpy(space, another.space, sizeof(*space) * size);
}

bool Stack::isFull() { 
    return top == size;
}

bool Stack::isEmpty() { 
    return top == 0;
}

void Stack::push(int data)
{
    space[top++] = data;
}

int Stack::pop() { 
    return space[--top];
}

Stack::~Stack() { 
    delete [] space;
}



