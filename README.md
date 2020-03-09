# data_structure
dynamic array 、linked_list、stack、queue with C Language

目前使用C语言实现了

- 动态数组
- 链表
- 栈
- 队列
- 二叉树
- AVL树
- 平衡二叉树

函数如下

#### 动态数组
```
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
```

####  链表

```
typedef struct linked_list linked_list;

//创建链表
linked_list *linked_list_create (void);

//获取链表的长度
int linked_list_length(linked_list *list);

//链表是否为空
bool linked_list_is_empty(linked_list *list);

//根据下标向链表加入元素
void linked_list_add_element_at_index(linked_list *list, const int index, void *const element);

//在链表的尾部加入元素
void linked_list_add_element(linked_list *list, void *const element);

//根据下标获取元素
void *linked_list_get_element_of_index(linked_list *list, int index);

//获取链表第一个元素
void *linked_list_get_first_element(linked_list *list);

//获取链表最后一个元素
void *linked_list_get_last_element(linked_list *list);

//删除链表中对应下标的节点元素
void linked_list_remove_element_at_index(linked_list *list, const int index);

//删除链表最后一个节点元素
void linked_list_remove_element(linked_list *list);

//销毁链表
void linked_list_destroy(linked_list *list);
```

#### 栈

```
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
```

#### 队列

```
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
```



#### 二叉树
```
typedef struct binary_tree_node {
    void *element;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
    struct binary_tree_node *parent;
    unsigned int height; //for avl    从下到上
    
} binary_tree_node;

typedef struct binary_tree {
    binary_tree_node *root;
    unsigned int node_count;
    
    //for binary_search_tree
    int (*compare_function)(void *element1, void *element2);
    
} binary_tree;


unsigned int binary_tree_node_count(binary_tree *tree);

bool binary_tree_is_empty(binary_tree *tree);

bool binary_tree_node_has_two_children(binary_tree_node *node);

bool binary_tree_node_is_left_child(binary_tree_node *node);

bool binary_tree_node_is_right_child(binary_tree_node *node);

//创建树节点
binary_tree_node *binary_tree_node_create(void *element);

//树的高度：使用队列
unsigned int binary_tree_height(binary_tree *tree);

//节点的前驱节点
binary_tree_node *binary_tree_predecessor_node(binary_tree *tree, binary_tree_node *node);

//节点的后继节点
binary_tree_node *binary_tree_successor_node(binary_tree *tree, binary_tree_node *node);
```
