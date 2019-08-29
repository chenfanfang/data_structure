//
//  queue.h
//  data_structure
//
//  Created by chenfanfang on 2019/8/29.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue queue;

//创建队列
queue *queue_create(void);

//判断队列是否为空
bool queue_is_empty(queue *q);

//入队
void queue_enqueue(queue *q, void *element);

//出队(出队返回的element元素指针的内存需要使用者自己进行管理)
void *queue_dequeue(queue *q);

//队列的长度
unsigned int queue_length(queue *q);

//获取对首元素
void *queue_get_head_element(queue *q);

//获取队尾元素
void *queue_get_tail_element(queue *q);

//销毁队列、释放内存
void queue_destroy(queue *q);

#endif /* queue_h */
