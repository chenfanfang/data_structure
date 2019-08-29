//
//  queue_test.c
//  data_structure
//
//  Created by chenfanfang on 2019/8/29.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include <stdio.h>
#include "queue.h"

//队列测试：入队自定义结构体数据
void test_queue_enqueue_custom_data(void) {
    
    printf("\n\ntest_queue_enqueue_custom_data\n\n");
    
    typedef struct custom_data {
        int value;
    } custom_data;
    
    size_t size_custom_data = sizeof(custom_data);
    
    //=============
    //    创建队列
    //=============
    queue *q = queue_create();
    
    //=============
    //     入列
    //=============
    for (int i = 0 ; i <= 10; i++) {
        custom_data *element = malloc(size_custom_data);
        element->value = i;
        queue_enqueue(q, element);
    }
    
    //=============
    //   获取队首元素
    //=============
    custom_data *head_element = queue_get_head_element(q);
    printf("head_element: %d\n",head_element->value);  //0
    
    //=============
    //   获取队尾元素
    //=============
    custom_data *tail_element = queue_get_tail_element(q);
    printf("tail_element: %d\n",tail_element->value); //10
    
    
    
    //=============
    //    出队
    //=============
    while (queue_is_empty(q) == false) {
        custom_data *dequeue_element = queue_dequeue(q);
        printf("出队的元素数据为:%d\n",dequeue_element->value);
        //注意:出队获取的元素的内存需要用户自己进行释放
        free(dequeue_element);
    }
    
    
    //=============
    //    销毁队列
    //=============
    
    queue_destroy(q);
}





//队列测试：入队基本数据类型  int
void test_queue_enqueue_int(void) {
    printf("\n\ntest_queue_enqueue_int\n\n");
    
    size_t size_int = sizeof(int);
    
    //=============
    //    创建队列
    //=============
    queue *q = queue_create();
    
    //=============
    //     入队
    //=============
    for (int i = 0 ; i <= 10; i++) {
        int *element = malloc(size_int);
        *element = i;
        queue_enqueue(q, element);
    }
    
    //=============
    //   获取队首元素
    //=============
    int *head_element = queue_get_head_element(q);
    printf("head_element: %d\n",*head_element);  //0
    
    //=============
    //   获取队尾元素
    //=============
    int *tail_element = queue_get_tail_element(q);
    printf("tail_element: %d\n",*tail_element); //10
    
    
    
    //=============
    //    出队
    //=============
    while (queue_is_empty(q) == false) {
        int *dequeue_element = queue_dequeue(q);
        printf("出队的元素数据为:%d\n",*dequeue_element);
        //注意:出队获取的元素的内存需要用户自己进行释放
        free(dequeue_element);
    }
    
    
    //=============
    //    销毁队列
    //=============
    queue_destroy(q);
}
