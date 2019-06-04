//
//  Stack.hpp
//  C++ 1
//
//  Created by glx on 2019/5/30.
//  Copyright © 2019 glx. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>

namespace GL
{
    struct Stack
    {
    public:
        Stack(int size = 10);
        Stack(const Stack & another);
        bool isFull();
        bool isEmpty();
        void push(int data);
        int pop();
        ~Stack();
    private:
        int size;
        int top;
        int * space;
        
    };
}

#endif /* Stack_hpp */
