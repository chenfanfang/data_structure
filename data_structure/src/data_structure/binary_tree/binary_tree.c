//
//  binary_tree_node.c
//  data_structure
//
//  Created by chenfanfang on 2019/8/29.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "binary_tree.h"
#include "queue.h"

unsigned int binary_tree_node_count(binary_tree *tree) {
    return tree->node_count;
}

bool binary_tree_is_empty(binary_tree *tree) {
    return tree->node_count == 0;
}

bool binary_tree_node_has_two_children(binary_tree_node *node) {
    
    if (node->left != NULL && node->right != NULL) {
        return true;
    }
    else {
        return false;
    }
}

//创建树节点
binary_tree_node *binary_tree_node_create(void *element) {
    
    binary_tree_node *node = (binary_tree_node *)malloc(sizeof(binary_tree_node));
    node->element = element;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

//树的高度：使用队列
unsigned int binary_tree_height(binary_tree *tree) {
    if (tree->root == NULL) return 0;
    
    // 树的高度
    int height = 0;
    // 存储着每一层的元素数量
    int level_node_count = 1;
    queue *_queue = queue_create();
    queue_enqueue(_queue, tree->root);
    
    while (queue_is_empty(_queue) == false) {
        binary_tree_node *node = queue_dequeue(_queue); //出队
        level_node_count--;
        
        if (node->left != NULL) {
            queue_enqueue(_queue, node->left);
        }
        
        if (node->right != NULL) {
            queue_enqueue(_queue, node->right);
        }
        
        if (level_node_count == 0) { // 意味着即将要访问下一层
            level_node_count = queue_length(_queue);
            height++;
        }
    }
    return height;
}




//节点的前驱节点
/*
 情况1：node->left != NULL
       predecessor = node->left->right->right....   中止条件right = NULL
 
 情况2：node->left == NULL && node->parrent != NULL
       predecessor = node->parrent->parrent.....    中止条件 node在parrent的右子树种
 
 情况3：node.left == NULL && node.parrent == NULL
       没有前驱节点
 
 */
binary_tree_node *binary_tree_predecessor_node(binary_tree *tree, binary_tree_node *node) {
    
    if (node == NULL) return NULL;
    
    binary_tree_node *predecessor_node = node->left;
    //情况1
    if (predecessor_node != NULL) {
        while (predecessor_node->right != NULL) {
            predecessor_node = predecessor_node->right;
        }
        return predecessor_node;
    }
    
    //情况2 情况3
    // 从父节点、祖父节点中寻找前驱节点
    while (node->parent != NULL && node != node->parent->right) {
        node = node->parent;
    }
    
    // node.parent == null
    // node == node.parent.right
    return node;
}



//节点的后继节点
/*
 情况1：node->right != NULL
 predecessor = node->right->left->left....   中止条件left = NULL
 
 情况2：node->right == NULL && node->parrent != NULL
 predecessor = node->parrent->parrent.....    中止条件 node在parrent的左子树种
 
 情况3：node.left == NULL && node.parrent == NULL
 没有后继节点
 
 */
binary_tree_node *binary_tree_successor_node(binary_tree *tree, binary_tree_node *node) {
    
    if (node == NULL) return NULL;
    
    binary_tree_node *successor_node = node->right;
    //情况1
    if (successor_node != NULL) {
        while (successor_node->left != NULL) {
            successor_node = successor_node->left;
        }
        return successor_node;
    }
    
    //情况2 情况3
    // 从父节点、祖父节点中寻找前驱节点
    while (node->parent != NULL && node != node->parent->left) {
        node = node->parent;
    }
    
    return node;
}
