//
//  stack.h
//  data_structure
//
//  Created by chenfanfang on 2019/8/28.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack stack;

//创建栈
stack *stack_create(void);
//判断
bool stack_is_empty(stack *_stack);
//栈中有多少元素
int stack_element_count(stack *_stack);
//入栈
void stack_push(stack *_stack, void *const element);
//出栈  注意：出栈的数据  void*  需要用户主动进行内存管理
void *stack_pop(stack *_stack);
//取栈顶元素
void *stack_get_top_element(stack *_stack);
//清空栈
void stack_remove_all(stack *_stack);
//销毁栈
void stack_destroy(stack *_stack);

#endif /* stack_h */
