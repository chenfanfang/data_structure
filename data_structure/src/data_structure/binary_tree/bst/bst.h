//
//  bst.h
//  data_structure
//
//  Created by chenfanfang on 2019/8/29.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#ifndef bst_h
#define bst_h

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_tree.h"

typedef binary_tree bst;
typedef binary_tree_node bst_node;


unsigned int bst_node_count(bst *tree);

bool bst_is_empty(bst *tree);

bool bst_node_has_two_children(bst_node *node);

bst_node *bst_node_create(void *element);

unsigned int bst_height(bst *tree);

bst_node *bst_predecessor_node(bst *tree, bst_node *node);

bst_node *bst_successor_node(bst *tree, bst_node *node);

//=============================================================

bst_node *bst_get_node(bst *tree ,void *element); //private

bst *bst_create(int (*compare_function)(void *element1, void *element2));

void bst_clear(bst *tree);

bst_node *bst_add(bst *tree, void *element);

//Users need to free node memory
bst_node *bst_remove(bst *tree, void *element);

bool bst_contains(bst *tree, void *element);

void bst_destroy(bst *tree);


#endif /* bst_h */
