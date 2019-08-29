//
//  bst.c
//  data_structure
//
//  Created by chenfanfang on 2019/8/29.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "bst.h"
#include <assert.h>


// 二叉树节点结构体
typedef struct bst_node {
    void *element;
    struct bst_node *left;
    struct bst_node *right;
    struct bst_node *parrent;
    
} bst_node;

struct bst {
    bst_node *root;
    int (*compare_function)(void *element1, void *element2);
    unsigned int node_count;
};


//创建树节点
bst_node *bst_node_create(void *element) {
    
    bst_node *node = (bst_node *)malloc(sizeof(bst_node));
    node->element = element;
    node->left = NULL;
    node->right = NULL;
    node->parrent = NULL;
    return node;
}

bst_node *bst_get_node(bst *tree ,void *element) {
    
    int compare_result = 0;
    bst_node *node = tree->root;
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
bst *bst_create(int (*compare_function)(void *element1, void *element2)) {
    
    if (compare_function == NULL) {
        printf("compare_function can not be NULL");
        assert(false);
    }
    
    bst *tree = calloc(1, sizeof(bst));
    tree->compare_function = compare_function;
    return tree;
}

int bst_node_count(bst *tree) {
    return tree->node_count;
}

bool tree_is_empty(bst *tree) {
    return tree->node_count == 0;
}

//未实现
void bst_clear(bst *tree) {
    
}

void bst_add(bst *tree, void *element) {
    
    bst_node *new_node = bst_node_create(element);
    //添加第一个节点
    if (tree->root == NULL) {
        tree->root = new_node;
        tree->node_count ++;
        return;
    }
    
    bst_node *parrent_node = NULL;
    bst_node *node = tree->root;
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
        new_node->parrent = parrent_node;
    }
    
    //新节点放置在左边
    else {
        parrent_node->left = new_node;
        new_node->parrent = parrent_node;
    }
    
}

bool bst_contains(bst *tree, void *element) {
    bst_node *bst_node = bst_get_node(tree, element);
    return bst_node != NULL;
}


void bst_destroy(bst *tree) {
    
}
