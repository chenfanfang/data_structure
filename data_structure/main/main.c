//
//  main.c
//  data_structure
//
//  Created by chenfanfang on 2019/8/28.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include <stdio.h>

#include "../test/array_test.c"
#include "../test/linked_list_test.c"
#include "../test/stack_test.c"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //================
    //    数组测试
    //================
//    test_array_int();
//    test_array_struct();

    
    //================
    //    链表测试
    //================
//    linked_list_test1();
//    linked_list_test2();
    
    //================
    //    栈测试
    //================
    test_stack_int();
    test_array_struct();
    
    return 0;
}
