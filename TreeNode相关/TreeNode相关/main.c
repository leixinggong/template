//
//  main.c
//  TreeNode相关
//
//  Created by glx on 2019/5/20.
//  Copyright © 2019 glx. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"
#include "TreeNode.h"

int main(int argc, const char * argv[]) {

    
    TreeNode * tree;
    initTree(&tree);
    
    insertTreeNode(&tree, 10);
    insertTreeNode(&tree, 3);
    insertTreeNode(&tree, 4);
    insertTreeNode(&tree, 65);
    insertTreeNode(&tree, 74);
    insertTreeNode(&tree, 27);
    insertTreeNode(&tree, 5);
    insertTreeNode(&tree, 9);
    insertTreeNode(&tree, 11);
    insertTreeNode(&tree, 2);
    insertTreeNode(&tree, 6);
    
    pretraverseBst(tree);
//    midtraverseBst(tree);
//    posttraverseBst(tree);
//    leveltraverseBst(tree);
//    
//    deleteTreeNode(&tree, getBinarySearchTreeNode(tree, 65));
//    midtraverseBst(tree);
    
    
    return 0;
}
