// 定义顺序表、销毁顺序表以及顺序表的增删改查
#include<stdio.h>
#include <stdlib.h>

/* 定义宏 */
#define MAX_SIZE 50     // 规定顺序表的最大长度为50
#define elementType int    // 规定数据元素的类型为int类型

/* 定义顺序表数据元素 */
typedef struct {
    elementType *value;     // 顺序表数据域
    int size;
}seqList;

/* 初始化顺序表 */
seqList* init_seqList() {
    // 给顺序表分配空间
    seqList* list = (seqList*)malloc(sizeof(seqList));
    if (list == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    // 给顺序表数据域分配空间
    list->value = (elementType*)malloc(sizeof(elementType) * MAX_SIZE);
    if (list->value == NULL) {
        printf("内存分配失败！\n");
        free(list);
        return NULL;
    }
    // 初始化长度
    list->size = 0;
    return list;
}

/* 打印顺序表 */
void print_list(const seqList* list) {
    if (list == NULL || list->size == 0) {
        printf("当前顺序表为空表\n");
        exit(EXIT_FAILURE);   // 等同于exit(1) -- 程序异常退出
    }
    printf("完整顺序表为:\n");
    for (int i = 0; i < list->size;i++) {
        printf("%d ",list->value[i]);
    }
}

int main() {
    seqList* list = init_seqList();
    if (list == NULL) free(list);
    return 0;
}




// Created by 柳贯一 on 2026/3/21.