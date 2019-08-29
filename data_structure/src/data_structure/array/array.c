//
//  array.c
//  data_structure
//
//  Created by chenfanfang on 2019/8/27.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "array.h"
#include <assert.h>
#include <stdbool.h>
#include <string.h>


struct array{
    
    unsigned int capacity; //数组的容量，不够可以自动进行扩容
    unsigned int length;   //当前数组中拥有数据的个数
    void **elements;
};

//判断数组是否需要扩容
void array_judge_capacity_is_enough(array *arr) {
    
    if (arr->length == arr->capacity) {
        arr->capacity = arr->capacity * 1.5;
        arr->elements = realloc(arr->elements, arr->capacity * sizeof(void *));
    }
}

//判断下标的合法性
void array_check_index(array *arr, int index) {
    
    if (index < 0 || index > arr->length - 1) {
        if (arr->length == 0) {
            printf("\n\n空数组越界:index:%d\n\n",index);
        }
        else {
            printf("\n\n数组越界 index:%d  range:[0  %d]\n\n",index, arr->length - 1);
        }
        
        assert(false);
    }
}

array *array_create(void) {
    
    array *array = calloc(1, sizeof(array));
    array->capacity = 10;
    array->length = 0;
    array->elements = calloc(array->capacity, sizeof(void *));
    return array;
}

bool array_is_empty(array *arr) {
    return arr->length == 0;
}

int array_length(array *arr) {
    return arr->length;
}

void *array_get_value_of_index(array *arr, int index) {
    array_check_index(arr, index);
    return arr->elements[index];
}

void *array_get_first_value(array *arr) {
    return array_get_value_of_index(arr, 0);
}

void *array_get_last_value(array *arr) {
    
    return array_get_value_of_index(arr, arr->length - 1);
}

void array_add_value(array *arr, void *const data) {
    
    array_insert_value_at_index(arr, arr->length, data);
}

void array_insert_value_at_index(array *arr, int index, void *const data) {
    
    array_judge_capacity_is_enough(arr);
    
    if (index != arr->length) {
        array_check_index(arr, index);
    }
    
    arr->length = arr->length + 1;
    for (int i = arr->length - 1; i > index; i--) {
        arr->elements[i] = arr->elements[i - 1];
    }
    
    arr->elements[index] = data;
}

void array_remove_at_index(array *arr, int index) {
    
    array_check_index(arr, index);
    
    void *element = arr->elements[index];
    free(element);
    
    for (int i = index; i < arr->length - 1; i++) {
        arr->elements[i] = arr->elements[i + 1];
    }
    
    arr->length = arr->length - 1;
    
}

void array_destroy(array *arr) {
    for (int i = 0; i < arr->length; i++) {
        free(arr->elements[i]);
    }
    free(arr->elements);
    free(arr);
}
