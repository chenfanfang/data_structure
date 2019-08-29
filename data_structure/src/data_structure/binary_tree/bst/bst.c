//
//  bst.c
//  data_structure
//
//  Created by chenfanfang on 2019/8/29.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "bst.h"
#include <assert.h>



binary_tree_node *bst_get_node(binary_tree *tree ,void *element) {
    
    int compare_result = 0;
    binary_tree_node *node = tree->root;
    while (node != NULL) {
        compare_result = (*(tree->compare_function))(element, node->element);//element - node->element;
        //相等，直接返回node
        if (compare_result == 0) {
            return node;
        }
        //大于，继续从right找
        else if (compare_result > 0) {
            node = node->right;
        }
        //小于，继续从left找
        else {
            node = node->left;
        }
    }
    return NULL;
}

//创建二叉搜索树， count 为intelementues数组的长度
binary_tree *bst_create(int (*compare_function)(void *element1, void *element2)) {
    
    if (compare_function == NULL) {
        printf("compare_function can not be NULL");
        assert(false);
    }
    
    binary_tree *tree = calloc(1, sizeof(binary_tree));
    tree->compare_function = compare_function;
    return tree;
}

//未实现
void bst_clear(binary_tree *tree) {
    
}

//二叉搜索树添节点
void bst_add(binary_tree *tree, void *element) {
    
    if (tree == NULL || element == NULL) {
        return;
    }
    
    binary_tree_node *new_node = binary_tree_node_create(element);
    //添加第一个节点
    if (tree->root == NULL) {
        tree->root = new_node;
        tree->node_count = tree->node_count + 1;
        return;
    }
    
    binary_tree_node *parrent_node = NULL;
    binary_tree_node *node = tree->root;
    int compare_result = 0; //新加的节点若等于比较的节点 ，则为0， 若大于则为1  若小于 则为-1
    do {
        compare_result = (*(tree->compare_function))(element, node->element);
        compare_result = 1;
        parrent_node = node;
        //新节点若比当前节点大，则继续从右边找node
        if (compare_result > 0) {
            node = node->right;
        }
        //新节点若比当前节点小，则继续从左边找node
        else if (compare_result < 0) {
            node = node->left;
            
        }
        //想等，则直接替换值，并且return
        else {
            node->element = element;
            return;
        }
        
    } while (node != NULL);
    
    //新节点放置在右边
    if (compare_result > 0) {
        parrent_node->right = new_node;
        new_node->parent = parrent_node;
    }
    
    //新节点放置在左边
    else {
        parrent_node->left = new_node;
        new_node->parent = parrent_node;
    }
    
    tree->node_count = tree->node_count + 1;
    
}



/*
 二叉搜索树 删除节点
 情况1：删除的节点是  叶子节点
       直接删除
         若 node == node->parrent->left      node->parrent->left = NULL
         若 node == node->parrent->right     node->parrent->right = NULL
         若 node.parrent == NULL             root = NULL
 
 情况2：删除的节点是  度为1的节点
       用子节点代替原节点的位置
        1、child 是 node->left 或者 child 是 node->right
        2、用child代替node的位置
         如果node是左子节点
         child->parrent = node->parrent     node->parrent->left = child
 
         如果node是右子节点
         child->parrent = node->parrent     node.parrent->right = child
 
         如果node是根节点
         root = child       child.parrent = NULL
 
 情况3：删除的节点是  度为2的节点
         1、先用前驱或者后继节点值覆盖要删除的节点的值
         2、然后删除相应的前驱或者后继节点
         注意：如果一个节点的度为2，那么它的前驱、后继节点的度只可能为1和0
 */
void bst_remove_node(binary_tree *tree, binary_tree_node *node) {
    if (node == NULL) return;
    
    tree->node_count = tree->node_count - 1;
    
    if (binary_tree_node_has_two_children(node)) { // 度为2的节点
        // 找到后继节点
        binary_tree_node *successor_node = binary_tree_successor_node(tree, node);
        
        // 用后继节点的值覆盖度为2的节点的值
        node->element = successor_node->element;
        // 删除后继节点
        node = successor_node;
    }
    
    // 删除node节点（此时node的度必然是1或者0）
    binary_tree_node *replacement_node = node->left != NULL ? node->left : node->right;
    
    if (replacement_node != NULL) { // node是度为1的节点
        // 更改parent
        replacement_node->parent = node->parent;
        // 更改parent的left、right的指向
        if (node->parent == NULL) { // node是度为1的节点并且是根节点
            tree->root = replacement_node;
            
        } else if (node == node->parent->left) {
            node->parent->left = replacement_node;
            
        } else { // node == node.parent.right
            node->parent->right = replacement_node;
        }
        
        
    } else if (node->parent == NULL) { // node是叶子节点并且是根节点
        tree->root = NULL;
        
    } else { // node是叶子节点，但不是根节点
        if (node == node->parent->left) {
            node->parent->left = NULL;
            
        } else { // node == node.parent.right
            node->parent->right = NULL;
        }
    }
}

//删除元素
void bst_remove(binary_tree *tree, void *element) {
    binary_tree_node *node = bst_get_node(tree, element);
    bst_remove_node(tree, node);
}

bool bst_contains(binary_tree *tree, void *element) {
    binary_tree_node *binary_tree_node = bst_get_node(tree, element);
    return binary_tree_node != NULL;
}


void bst_destroy(binary_tree *tree) {
    
}
