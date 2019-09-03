//
//  binary_tree.h
//  data_structure
//
//  Created by chenfanfang on 2019/8/29.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#ifndef binary_tree_h
#define binary_tree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct binary_tree_node {
    void *element;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
    struct binary_tree_node *parent;
    unsigned int height; //for avl    从下到上
    
} binary_tree_node;

typedef struct binary_tree {
    binary_tree_node *root;
    unsigned int node_count;
    
    //for binary_search_tree
    int (*compare_function)(void *element1, void *element2);
    
} binary_tree;


unsigned int binary_tree_node_count(binary_tree *tree);

bool binary_tree_is_empty(binary_tree *tree);

bool binary_tree_node_has_two_children(binary_tree_node *node);

bool binary_tree_node_is_left_child(binary_tree_node *node);

bool binary_tree_node_is_right_child(binary_tree_node *node);

//创建树节点
binary_tree_node *binary_tree_node_create(void *element);

//树的高度：使用队列
unsigned int binary_tree_height(binary_tree *tree);

//节点的前驱节点
binary_tree_node *binary_tree_predecessor_node(binary_tree *tree, binary_tree_node *node);

//节点的后继节点
binary_tree_node *binary_tree_successor_node(binary_tree *tree, binary_tree_node *node);



#endif /* binary_tree_h */
