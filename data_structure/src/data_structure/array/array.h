//
//  array.h
//  data_structure
//
//  Created by chenfanfang on 2019/8/27.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#ifndef array_h
#define array_h


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct array array;


//创建数组
array *array_create(void);

//判断数组是否为空数组
bool array_is_empty(array *arr);

//获取数组的长度
int array_length(array *arr);

//获取数组中指定下标的元素
void *array_get_value_of_index(array *arr, int index);

//获取数组中第一个元素
void *array_get_first_value(array *arr);

//获取数组中最后一个元素
void *array_get_last_value(array *arr);

//往数组中添加元素【添加至尾部】
void array_add_value(array *arr, void *const data);

//往数组中指定位置插入元素
void array_insert_value_at_index(array *arr, int index, void *const data);

//移除数组中指定位置的元素
void array_remove_at_index(array *arr, int index);

//销毁数组、释放内存
void array_destroy(array *arr);


#endif /* array_h */
