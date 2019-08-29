//
//  stack_test.c
//  data_structure
//
//  Created by chenfanfang on 2019/8/29.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include <stdio.h>
#include "stack.h"

void test_stack_int(void) {
    
    size_t bytes_per_element = sizeof(int);
    stack *_stack = stack_create();
    
    for (int i = 0; i < 11; i++) {
        int *element = malloc(bytes_per_element);
        *element = i;
        stack_push(_stack, element);
        
    }
    
    printf("test_stack_int:\n");
    //出栈
    while (stack_is_empty(_stack) == false) {
        int *element = stack_pop(_stack);
        printf("%d 、",*element);
        free(element);
    }
    
    //控制台输出:10 、9 、8 、7 、6 、5 、4 、3 、2 、1 、0 、
    printf("\n\n");
    
    stack_destroy(_stack);
}

void test_stack_custom_data(void) {
    
    typedef struct stack_custom_data {
        int value;
        
    } stack_custom_data;
    
    size_t bytes_per_element = sizeof(stack_custom_data);
    //创建栈
    stack *_stack = stack_create();
    
    printf("test_stack_custom_data:\n");
    //入栈
    for (int i = 0; i < 9; i++) {
        stack_custom_data *element = malloc(bytes_per_element);
        element->value = i;
        stack_push(_stack, element);
    }
    
    //出栈
    while (stack_is_empty(_stack) == false) {
        stack_custom_data *element = stack_pop(_stack);
        printf("%d 、",element->value);
        free(element);
    }
    //控制台输出:8 、7 、6 、5 、4 、3 、2 、1 、0 、
    
    printf("\n\n");
    
    stack_destroy(_stack);
    
}
