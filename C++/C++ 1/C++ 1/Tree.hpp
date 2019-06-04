//
//  Tree.hpp
//  C++ 1
//
//  Created by glx on 2019/5/30.
//  Copyright © 2019 glx. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <iostream>

namespace GL
{
    struct TreeNode
    {
        int data;
        TreeNode * left;
        TreeNode * right;
    };
    
    struct Tree
    {
    public:
        Tree();
        
    private:
        TreeNode * node;
    };
}

#endif /* Tree_hpp */
