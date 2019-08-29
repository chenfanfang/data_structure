//
//  linked_list.h
//  data_structure
//
//  Created by chenfanfang on 2019/8/28.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linked_list linked_list;

//创建链表
linked_list *linked_list_create (void);

//获取链表的长度
int linked_list_length(linked_list *list);

//链表是否为空
bool linked_list_is_empty(linked_list *list);

//根据下标向链表加入元素
void linked_list_add_element_at_index(linked_list *list, const int index, void *const element);

//在链表的尾部加入元素
void linked_list_add_element(linked_list *list, void *const element);

//根据下标获取元素
void *linked_list_get_element_of_index(linked_list *list, int index);

//获取链表第一个元素
void *linked_list_get_first_element(linked_list *list);

//获取链表最后一个元素
void *linked_list_get_last_element(linked_list *list);

//删除链表中对应下标的节点元素
void linked_list_remove_element_at_index(linked_list *list, const int index);

//删除链表最后一个节点元素
void linked_list_remove_element(linked_list *list);

//销毁链表
void linked_list_destroy(linked_list *list);


#endif /* linked_list_h */
