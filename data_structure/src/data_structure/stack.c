//
//  stack.c
//  data_structure
//
//  Created by chenfanfang on 2019/8/28.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "stack.h"
#include <assert.h>

typedef struct stack_node{
    void *element;
    struct stack_node *next;
} stack_node;

struct stack {
    int element_count; //栈中有多少个元素
    stack_node *top; //栈顶
    
};


//创建栈
stack *stack_create(void) {
    stack *_stack = calloc(1, sizeof(stack));
    _stack->top = NULL;
    _stack->element_count = 0;
    return _stack;
}

//判空
bool stack_is_empty(stack *_stack) {
    return _stack->element_count == 0;
}

//栈中有多少元素
int stack_element_count(stack *_stack) {
    return _stack->element_count;
}

//入栈
void stack_push(stack *_stack, void *const element) {
    
    _stack->element_count = _stack->element_count + 1;
    stack_node *new_node = calloc(1, sizeof(stack_node));
    new_node->element = element;
    
    new_node->next = _stack->top;
    _stack->top = new_node;
    
}
//出栈
void *stack_pop(stack *_stack) {
    if (_stack->top == NULL) {
        printf("栈中没有数据，无法pop\n\n");
        assert(false);
    }
    
    stack_node *top_node = _stack->top;
    _stack->top = top_node->next;
    void *element = top_node->element;
    free(top_node);
    _stack->element_count = _stack->element_count - 1;
    return element;
    
}
//取栈顶元素
void *stack_get_top_element(stack *_stack) {
    if (_stack->top == NULL) {
        printf("栈中没有数据，无法获取数据\n\n");
        assert(false);
    }
    
    void *element = _stack->top->element;
    return element;
}

//清空栈
void stack_remove_all(stack *_stack) {
    struct stack_node *top_node = _stack->top;
    struct stack_node *old_top_node  = top_node;
    while (top_node != NULL) {
        old_top_node = top_node;
        top_node = top_node->next;
        free(old_top_node->element);
        free(old_top_node);
    }
    
    _stack->element_count = 0;
    
    if (top_node != NULL) {
        free(top_node->element);
        free(top_node);
    }
    _stack->top = NULL;
}
//销毁栈
void stack_destroy(stack *_stack) {
    stack_remove_all(_stack);
    free(_stack);
}
