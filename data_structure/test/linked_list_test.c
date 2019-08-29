//
//  linked_list_test.c
//  data_structure
//
//  Created by chenfanfang on 2019/8/29.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include <stdio.h>

#include "linked_list.h"

//测试1、数据为自定义的结构体数据
void linked_list_test1(void) {
    
    typedef struct custom_data {
        int value;
        
    } custom_data;
    
    size_t size = sizeof(custom_data);
    
    
    //尾部添加元素
    linked_list *list = linked_list_create();
    for (int i = 11; i <= 22; i++) {
        custom_data *data = malloc(sizeof(size));
        data->value = i;
        linked_list_add_element(list, data);
    }
    //11、12、13、14、15、16、17、18、19、20、21、22
    
    
    //根据下标添加元素
    custom_data *data = malloc(sizeof(size));
    data->value = 0;
    linked_list_add_element_at_index(list, 0, data);
    
    //0、11、12、13、14、15、16、17、18、19、20、21、22
    
    
    //删除最后一个元素
    linked_list_remove_element(list);
    //0、11、12、13、14、15、16、17、18、19、20、21
    
    //根据下标删除元素
    linked_list_remove_element_at_index(list, 2);
    //0、11、13、14、15、16、17、18、19、20、21
    
    
    printf("linked_list_test1\n");
    int list_length = linked_list_length(list);
    for (int i = 0; i < list_length; i++) {
        custom_data *data = linked_list_get_element_of_index(list, i);
        printf("%d、",data->value);
    }
    
    printf("\n\n");
}



//测试1、数据为基本数据类型  int
void linked_list_test2(void) {
    
    
    size_t size = sizeof(int);
    
    
    //尾部添加元素
    linked_list *list = linked_list_create();
    for (int i = 11; i <= 22; i++) {
        int *data = malloc(sizeof(size));
        *data = i;
        linked_list_add_element(list, data);
    }
    //11、12、13、14、15、16、17、18、19、20、21、22
    
    
    //根据下标添加元素
    int *data = malloc(sizeof(size));
    *data = 0;
    linked_list_add_element_at_index(list, 0, data);
    
    //0、11、12、13、14、15、16、17、18、19、20、21、22
    
    
    //删除最后一个元素
    linked_list_remove_element(list);
    //0、11、12、13、14、15、16、17、18、19、20、21
    
    //根据下标删除元素
    linked_list_remove_element_at_index(list, 2);
    //0、11、13、14、15、16、17、18、19、20、21
    
    
    printf("linked_list_test2\n");
    int list_length = linked_list_length(list);
    for (int i = 0; i < list_length; i++) {
        int *data = linked_list_get_element_of_index(list, i);
        printf("%d、",*data);
    }
    
    printf("\n\n");
    
}
