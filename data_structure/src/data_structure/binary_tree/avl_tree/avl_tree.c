//
//  avl_tree.c
//  data_structure
//
//  Created by chenfanfang on 2019/9/3.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "avl_tree.h"

//private
int avl_tree_balance_factor(avl_tree_node *node);

void avl_tree_update_node_height(avl_tree_node *node);

avl_tree_node *avl_tree_taller_child_node(avl_tree_node *node);

void avl_tree_after_add_node(avl_tree *tree, avl_tree_node *node);

void avl_tree_after_remove_node(avl_tree *tree, avl_tree_node *node);

void avl_tree_restore_balance(avl_tree *tree, avl_tree_node *grand_node);

void avl_tree_rotate_left(avl_tree *tree, avl_tree_node *grand_node);

void avl_tree_rotate_right( avl_tree *tree, avl_tree_node *grand_node);

void avl_tree_after_rotate(avl_tree *tree, avl_tree_node *grand_node, avl_tree_node *parent_node, avl_tree_node *parent_child_node);


//=========================
//   inherit binary_tree
//=========================
unsigned int avl_tree_node_count(avl_tree *tree) {
    return binary_tree_node_count(tree);
}

bool avl_tree_is_empty(avl_tree *tree) {
    return binary_tree_is_empty(tree);
}

bool avl_tree_node_has_two_children(avl_tree_node *node) {
    return binary_tree_node_has_two_children(node);
}

avl_tree_node *avl_tree_node_create(void *element) {
    avl_tree_node *node = binary_tree_node_create(element);
    node->height = 1;
    return node;
}

unsigned int avl_tree_height(avl_tree *tree) {
    return binary_tree_height(tree);
}

avl_tree_node *avl_tree_predecessor_node(avl_tree *tree, avl_tree_node *node) {
    return binary_tree_predecessor_node(tree, node);
}

avl_tree_node *avl_tree_successor_node(avl_tree *tree, avl_tree_node *node) {
    return binary_tree_successor_node(tree, node);
}



//==================
//   inherit bst
//==================
avl_tree_node *avl_tree_get_node(avl_tree *tree ,void *element) {
    
    return bst_get_node(tree, element);
}

avl_tree *avl_tree_create(int (*compare_function)(void *element1, void *element2)) {
    
    return bst_create(compare_function);
}

void avl_tree_clear(avl_tree *tree) {
    bst_clear(tree);
}

void avl_tree_add(avl_tree *tree, void *element) {
    
    bst_add(tree, element);
}

//删除元素
void avl_tree_remove(avl_tree *tree, void *element) {
    bst_remove(tree, element);
}

bool avl_tree_contains(avl_tree *tree, void *element) {
    return bst_contains(tree, element);
}


void avl_tree_destroy(avl_tree *tree) {
    bst_destroy(tree);
}


//==================
//     avl_tree
//==================

int avl_tree_balance_factor(avl_tree_node *node) { //平衡因子
    int left_height = node->left == NULL ? 0 : node->left->height;
    int right_height = node->right == NULL ? 0 : node->right->height;
    return left_height - right_height;
}

void avl_tree_update_node_height(avl_tree_node *node) {//更新节点高度
    
    int left_height = node->left == NULL ? 0 : node->left->height;
    int right_height = node->right == NULL ? 0 : node->right->height;
    
    if (left_height > right_height) {
        node->height = left_height + 1;
    }
    else {
        node->height = right_height + 1;
    }
}

avl_tree_node *avl_tree_taller_child_node(avl_tree_node *node) { //获取高度跟高的子节点
    
    int left_height = node->left == NULL ? 0 : node->left->height;
    int right_height = node->right == NULL ? 0 : node->right->height;
    
    if (left_height > right_height) {
        return node->left;
    }
    else if (left_height < right_height) {
        return node->right;
    }
    
    else { //如果高度相等、则定一个规则：返回左边的节点
        return node->left;
    }
}

bool avl_tree_is_balance(avl_tree_node *node) { //avl树是否平衡
    int balance_factor = avl_tree_balance_factor(node);
    if (balance_factor >= -1 && balance_factor <= 1 ) {
        return true;
    }
    else {
        return false;
    }
}




void avl_tree_after_add_node(avl_tree *tree, avl_tree_node *node) {
    
    while ((node = node->parent) != NULL) {
        
        //平衡
        if (avl_tree_is_balance(node)) {
            //更新高度
            avl_tree_update_node_height(node);
        }
        //不平衡
        else {
            avl_tree_restore_balance(tree,node);
            break;
        }
    }
}

void avl_tree_after_remove_node(avl_tree *tree, avl_tree_node *node) {
    
    //删除一个节点，最坏情况可能会导致整棵树失衡，所以需要将整棵树的高度重新更新
    while ((node = node->parent) != NULL) {
        
        //平衡
        if (avl_tree_is_balance(node)) {
            //更新高度
            avl_tree_update_node_height(node);
        }
        //不平衡
        else {
            avl_tree_restore_balance(tree,node);
        }
    }
}


void avl_tree_restore_balance(avl_tree *tree, avl_tree_node *grand_node) {
    
    avl_tree_node *parrent_node = avl_tree_taller_child_node(grand_node);
    avl_tree_node *node = avl_tree_taller_child_node(parrent_node);
    
    if (binary_tree_node_is_left_child(parrent_node)) { //L
        
        if (binary_tree_node_is_left_child(node)) { //LL
            avl_tree_rotate_right(tree,grand_node);
        }
        else { //LR
            avl_tree_rotate_left(tree,parrent_node); //变成LL
            avl_tree_rotate_right(tree, grand_node);
        }
    }
    
    else { //R
        
        if (binary_tree_node_is_left_child(node)) { //RL
            avl_tree_rotate_right(tree, parrent_node);
            avl_tree_rotate_left(tree, grand_node);
        }
        else { //RR
            avl_tree_rotate_left(tree, grand_node);
        }
    }
}

void avl_tree_rotate_left(avl_tree *tree, avl_tree_node *grand_node) {
    
    avl_tree_node *parrent_node = grand_node->right;
    avl_tree_node *parrent_child_node = parrent_node->left;
    grand_node->left = parrent_child_node;
    parrent_node->left = grand_node;
    
    avl_tree_after_rotate(tree, grand_node, parrent_node, parrent_child_node);
    
}

void avl_tree_rotate_right( avl_tree *tree, avl_tree_node *grand_node) {
    
    avl_tree_node *parent_node = grand_node->left;
    avl_tree_node *parent_child_node = parent_node->right;
    grand_node->left = parent_child_node;
    parent_node->right = grand_node;

    avl_tree_after_rotate(tree, grand_node, parent_node, parent_child_node);
}

void avl_tree_after_rotate(avl_tree *tree, avl_tree_node *grand_node, avl_tree_node *parent_node, avl_tree_node *parent_child_node) {
    // 让parent_node成为子树的根节点
    parent_node->parent = grand_node->parent;
    if (binary_tree_node_is_left_child(grand_node)) {
        grand_node->parent->left = parent_node;
    }
    else if (binary_tree_node_is_right_child(grand_node)) {
        grand_node->parent->right = parent_node;
    }
    else { //grand是根节点
        tree->root = parent_node;
    }
    
    
    //更新parent_child_node的parent
    if (parent_child_node != NULL) {
        parent_child_node->parent = grand_node;
    }
    
    // 更新grand的parent
    grand_node->parent = parent_node;
    
    //更新高度
    avl_tree_update_node_height(grand_node);
    avl_tree_update_node_height(parent_node);
    
}

