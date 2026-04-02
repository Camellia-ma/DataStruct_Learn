// 定义顺序表、销毁顺序表以及顺序表的增删改查
#include<stdio.h>
#include <stdlib.h>

/* 定义宏 */
#define MAX_SIZE 50     // 规定顺序表的最大长度为50
#define elementType int    // 规定数据元素的类型为int类型
#define SUCCESS 1
#define FAILURE 0
#define NOT_FOUND (-1)


/* 定义顺序表数据元素 */
typedef struct {
    elementType *value;     // 顺序表数据域
    int size;               // 顺序表长度 -- 初始化为0
}seqList;

/* 初始化顺序表 */
seqList* init_seqList() {
    // 给顺序表分配空间
    seqList* list = (seqList*)malloc(sizeof(seqList));
    if (list == NULL) {
        printf("顺序表内存分配失败！\n");
        return NULL;
    }
    // 给顺序表数据域分配空间
    list->value = (elementType*)malloc(sizeof(elementType) * MAX_SIZE); // 顺序表的大小定义后不可更改
    if (list->value == NULL) {
        printf("顺序表数据域内存分配失败！\n");
        free(list);
        return NULL;
    }
    // 初始化长度
    list->size = 0;
    return list;
}

/* 插入顺序表数据元素 */
// 注：向顺序表内插入元素最好情况下时间复杂度为O(1),最坏情况为O(n)平均时间复杂度为O(n)
int insert_element(seqList* list,const elementType insert_data,const int index) {
    // 检查索引是否合法以及顺序表是否已满
    if (index < 1 || index > list->size + 1) {
        printf("非法索引.\n");
        return FAILURE;
    }
    if (list->size == MAX_SIZE) {
        printf("顺序表已满.\n");
        return FAILURE;
    }
    // 从表尾向后移一位为新插入的数据创造空间
    for (int i = list->size;i>=index;i--) {
        list->value[i] = list->value[i-1];
    }
    // 插入值并增加顺序表长度
    list->value[index - 1] = insert_data;
    list->size++;
    return SUCCESS;
}

/* 删除顺序表元素 */
// 注：最佳情况下时间复杂度为O(1),最坏情况为O(n)平均时间复杂度为O(n)
int delete_element(seqList* list,const int delete_index,elementType* delete_value) {
    // 检查索引是否合法以及顺序表是否为空表
    if (delete_index < 1 || delete_index > list->size) {
        printf("非法索引!\n");
        return FAILURE;
    }
    if (list->size == 0) {
        printf("顺序表为空表!\n");
        return FAILURE;
    }
    *delete_value = list->value[delete_index-1];
    for (int i = delete_index;i<list->size;i++) {
        list->value[i-1] = list->value[i];
    }
    list->size--;
    return SUCCESS;
}

/* 查找数据元素 */
// 注：最佳情况下时间复杂度为O(1),最坏情况为O(n)平均时间复杂度为O(n)
int select_element(const seqList* list,const elementType select_value) {
    for (int i = 0;i < list->size;i++) {
        if (list->value[i] == select_value) return i+1;
    }
    return NOT_FOUND;
}

/* 打印顺序表 */
void print_list(const seqList* list) {
    printf("完整顺序表为:\n|");
    for (int i = 0;i<list->size;i++) {
        printf(" %d | ",list->value[i]);
    }
    printf("\n");
}

/* 释放顺序表 */
int free_list(seqList* list) {
    if (list->value != NULL) {
        free(list->value);
    }
    free(list);
    list = NULL;
    return SUCCESS;
}

int main() {
    seqList* list = init_seqList();
    if (list == NULL) {
        printf("初始化失败,程序退出.");
        exit(EXIT_FAILURE);
    }
    for (int i = 0;i <= 10;i++) {
        insert_element(list,i*10,i+1);
    }
    print_list(list);

    elementType delete_value = 0;
    if (delete_element(list,3,&delete_value)) {
        printf("位于第3为的数据元素删除成功,值为：%d\n",delete_value);
    }
    print_list(list);

    const int index = select_element(list,30);
    if (index == NOT_FOUND) printf("该值不位于顺序表中.");
    else  printf("该值位于顺序表第 %d 位.",index);
    free_list(list);
    return 0;
}




// Created by 柳贯一 on 2026/3/21.