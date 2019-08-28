//
//  array_test.c
//  data_structure
//
//  Created by chenfanfang on 2019/8/27.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include <stdio.h>
#include "array.h"

//测试：数组存放基本数据类型 int
void test_array_int(void) {
    
    size_t int_size = sizeof(int);
    
    array *arr = array_create();
    
    //=======================
    //       添加元素
    //=======================
    for (int i = 0; i < 21; i++) {
        int *data = malloc(int_size);
        *data = i;
        array_add_value(arr, data);
    }
    //0、1、2、3、4、5、6、7、8、9、10、11、12、13、14、15、16、17、18、19、20、
    
    
    //=======================
    //       插入元素
    //=======================
    int *insert_data = malloc(int_size);
    *insert_data = 999;
    array_insert_value_at_index(arr, 1, insert_data);
    // 0、999、1、2、3、4、5、6、7、8、9、10、11、12、13、14、15、16、17、18、19、20
    
    
    //=======================
    //       移除元素
    //=======================
    array_remove_at_index(arr, 0);
    //999、1、2、3、4、5、6、7、8、9、10、11、12、13、14、15、16、17、18、19、20
    
    
    //=======================
    //       获取元素
    //=======================
    printf("test_array_int\n\n");
    for (int i = 0; i < array_length(arr); i++) {
        
        int *data = array_get_value_of_index(arr, i);
        printf("%d、",*data);
    }
    
    printf("\n\n");
    array_destroy(arr);
}


//测试：数组存放自定义结构体
void test_array_struct(void) {
    
    struct custom_data {
        int value;
    };
    
    size_t custom_data_size = sizeof(struct custom_data);
    
    array *arr = array_create();
    
    //=======================
    //       添加元素
    //=======================
    for (int i = 0; i < 21; i++) {
        struct custom_data *data = malloc(custom_data_size);
        data->value = i;
        array_add_value(arr, data);
    }
    //0、1、2、3、4、5、6、7、8、9、10、11、12、13、14、15、16、17、18、19、20、
    
    
    //=======================
    //       插入元素
    //=======================
    struct custom_data *insert_data = malloc(custom_data_size);
    insert_data->value = 999;
    array_insert_value_at_index(arr, 1, insert_data);
    // 0、999、1、2、3、4、5、6、7、8、9、10、11、12、13、14、15、16、17、18、19、20
    
    
    //=======================
    //       移除元素
    //=======================
    array_remove_at_index(arr, 0);
    //999、1、2、3、4、5、6、7、8、9、10、11、12、13、14、15、16、17、18、19、20
    
    
    //=======================
    //       获取元素
    //=======================
    printf("test_array_struct\n\n");
    for (int i = 0; i < array_length(arr); i++) {
        
        struct custom_data *data = array_get_value_of_index(arr, i);
        printf("%d、",data->value);
    }
    
    printf("\n\n");
    array_destroy(arr);
    
}
