//
//  avl_tree.h
//  data_structure
//
//  Created by chenfanfang on 2019/9/3.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#ifndef avl_tree_h
#define avl_tree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_tree.h"
#include "bst.h"

typedef binary_tree avl_tree;
typedef binary_tree_node avl_tree_node;


unsigned int avl_tree_node_count(avl_tree *tree);

bool avl_tree_is_empty(avl_tree *tree);

bool avl_tree_node_has_two_children(avl_tree_node *node);

avl_tree_node *avl_tree_node_create(void *element);

unsigned int avl_tree_height(avl_tree *tree);

avl_tree_node *avl_tree_predecessor_node(avl_tree *tree, avl_tree_node *node);

avl_tree_node *avl_tree_successor_node(avl_tree *tree, avl_tree_node *node);

//=============================================================

avl_tree_node *avl_tree_get_node(avl_tree *tree ,void *element);

avl_tree *avl_tree_create(int (*compare_function)(void *element1, void *element2));

void avl_tree_clear(avl_tree *tree);

void avl_tree_add(avl_tree *tree, void *element);

void avl_tree_remove(avl_tree *tree, void *element);

bool avl_tree_contains(avl_tree *tree, void *element);

void avl_tree_destroy(avl_tree *tree);

#endif /* avl_tree_h */
