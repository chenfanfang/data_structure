//
//  queue.c
//  data_structure
//
//  Created by chenfanfang on 2019/8/29.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "queue.h"
#include <assert.h>


typedef struct queue_node {
    void *element;
    struct queue_node *next;
}queue_node;


struct queue {
    queue_node *head;
    queue_node *tail;
    unsigned int length;
};

void queue_check_queue_can_not_be_null(queue *q) {
    if (q == NULL) {
        printf("queue can not be NULL");
        assert(false);
    }
}

//初始化队列
queue *queue_create(void) {
    
    queue *q = calloc(1, sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;
    return q;
}

//判断队列是否为空
bool queue_is_empty(queue *q) {
    queue_check_queue_can_not_be_null(q);
    return q->length == 0;
}

//入队
void queue_enqueue(queue *q, void *element) {
    
    if (element == NULL) {
        printf("enqueue element can not be NULL");
        assert(false);
    }
    
    queue_check_queue_can_not_be_null(q);
    
    queue_node *node = (queue_node *)malloc(sizeof(queue_node));
    node->element = element;
    node->next = NULL;//尾插法，插入元素指向空
    if(q->head == NULL) {
        
        q->head = node;
        q->tail = node;
    }
    else{
        q->tail->next = node;
        q->tail= node;
    }
    
    q->length = q->length + 1;
}

//出队
void *queue_dequeue(queue *q) {
    
    queue_check_queue_can_not_be_null(q);
    
    queue_node *dequeue_node = q->head;
    
    if(q->length == 0) {//判断队列是否为空
        printf("empty queue can not dequeue");
        assert(false);
    }
    
    if(q->length == 1) {//是否只有一个元素
        q->head = NULL;
        q->tail = NULL;
    }
    else{
        q->head = q->head->next;
    }
    
    void *element = dequeue_node->element;
    free(dequeue_node);
    
    q->length = q->length - 1;
    return element;
}


unsigned int queue_length(queue *q) {
    queue_check_queue_can_not_be_null(q);
    return q->length;
}


void *queue_get_head_element(queue *q) {
    queue_check_queue_can_not_be_null(q);
    return q->head->element;
}

void *queue_get_tail_element(queue *q) {
    queue_check_queue_can_not_be_null(q);
    return q->tail->element;
}


//销毁队列、释放内存
void queue_destroy(queue *q) {
    
    if (q == NULL) {
        return;
    }
    queue_node *node = q->head;
    queue_node *pre_node;
    q->length = 0;
    while (node) {
        pre_node = node;
        node = node->next;
        free(pre_node->element);
        free(pre_node);
    }
    
}
