//
//  linked_list.c
//  data_structure
//
//  Created by chenfanfang on 2019/8/28.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "linked_list.h"
#include <assert.h>
#include <string.h>

typedef struct linked_list_node {
    
    struct linked_list_node *next;
    struct linked_list_node *prev;
    void *element;
    
} linked_list_node;

struct linked_list {
    
    int length; //链表长度、也就是链表中有多少个元素
    linked_list_node *head;
};

void linked_list_check_index(linked_list *list ,int index) {
    if (index < 0 || index >= list->length) {
        if (linked_list_is_empty(list) == true) {
            printf("空链表下标越界 index:%d",index);
        }
        else {
            printf("下标越界: index=%d  界限[%d  %d]",index, 0, list->length - 1);
        }
        assert(false);
    }
}



linked_list *linked_list_create (void) {
    
    struct linked_list *list;
    list = malloc(sizeof(linked_list));
    if (list == NULL) {
        return NULL;
    }
    
    list->length = 0;
    list->head = NULL;
    return list;
}


int linked_list_length(linked_list *list) {
    return list->length;
}

bool linked_list_is_empty(linked_list *list) {
    
    return linked_list_length(list) == 0;
}

void linked_list_add_element_at_index(linked_list *list, const int index, void *const element) {
    
    if (element == NULL) {
        printf("element can not be NULL");
        assert(false);
    }
    
    //下标的合法性检测
    if (index != list->length) {
        linked_list_check_index(list, index);
    }
    
    //创建节点
    linked_list_node *new_node = calloc(1, sizeof(linked_list_node));
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->element = element;
    
    list->length = list->length + 1;
    
    //头结点为NULL的情况
    if (list->head == NULL) {
        list->head = new_node;
        return;
    }
    
    linked_list_node *index_node = list->head;
    int index_flag = 0;
    while (index_flag < index && index_node->next != NULL) {
        index_flag++;
        index_node = index_node->next;
    }
    
    //中间插入元素
    if (index_flag == index) {
        new_node->next = index_node;
        new_node->prev = index_node->prev;
        
        if (new_node->prev != NULL) {
            new_node->prev->next = new_node;
        }
        index_node->prev = new_node;
    }
    
    //最后添加元素
    else {
        index_node->next = new_node;
        new_node->prev = index_node;
    }
    
    if (index == 0) {
        list->head = new_node;
    }
}


//在链表的尾部加入元素
void linked_list_add_element(linked_list *list, void *const element) {
    
    linked_list_add_element_at_index(list, list->length, element);
}

//根据下标获取元素
void *linked_list_get_element_of_index(linked_list *list, int index) {
    
    if (list->head == NULL && index == 0) {
        return NULL;
    }
    
    linked_list_check_index(list, index);
    
    linked_list_node *index_node = list->head;
    int index_flag = 0;
    while (index_flag < index) {
        index_flag++;
        index_node = index_node->next;
    }
    
    return index_node->element;
    
}

//获取链表第一个元素
void *linked_list_get_first_element(linked_list *list) {
    return linked_list_get_element_of_index(list, 0);
}

//获取链表最后一个元素
void *linked_list_get_last_element(linked_list *list) {
    return linked_list_get_element_of_index(list, list->length - 1);
}



//删除链表中对应下标的节点元素
void linked_list_remove_element_at_index(linked_list *list, const int index) {
    
    //下标合法性检查
    linked_list_check_index(list, index);
    
    linked_list_node *index_node = list->head;
    int index_flag = 0;
    while (index_flag < index) {
        index_flag ++;
        index_node = index_node->next;
    }
    
    linked_list_node *prev_node = index_node->prev;
    linked_list_node *next_node = index_node->next;
    
    prev_node->next = next_node;
    if (next_node != NULL) {
        next_node->prev = prev_node;
    }
    
    free(index_node->element);
    free(index_node);
    
    list->length = list->length - 1;
    
}

//删除链表最后一个节点元素
void linked_list_remove_element(linked_list *list) {
    
    linked_list_remove_element_at_index(list, list->length - 1);
    
}


//销毁链表
void linked_list_destroy(linked_list *list) {
    
    linked_list_node *current_node = list->head;
    linked_list_node *pre_node = NULL;
    
    while (current_node != NULL) {
        pre_node = current_node;
        current_node = current_node->next;
        free(pre_node);
    }
    
    free(list);
}
