// 实现单链表的创建、销毁以及增删改查
#include<stdio.h>
#include<stdlib.h>

#define elementType int
#define SUCCESS 1
#define FAILURE 0
#define NOT_FOUND (-1)


// 定义链表的数据结构
typedef struct list_node{
    elementType data;      // 链表数据域
    struct list_node* next;
}list_node,*LINK_LIST;

/* 初始化链表 -- 带头结点 */
LINK_LIST init_list() {
    list_node* head = (list_node *)malloc(sizeof(list_node));
    if (head == NULL) {
        printf("申请头节点失败.\n");
        return NULL;
    }else head->next = NULL;
    return  head;
}

/* 插入节点 -- 平均时间复杂度O(n) */
int insert_node(LINK_LIST list,const int insert_index,const elementType insert_data) {
    if (insert_index < 1) {
        printf("非法索引.\n");
        return FAILURE;
    }
    list_node* current_node = list;
    int current_index = 0;
    while (current_node && current_index < insert_index - 1) {
        current_node = current_node->next;
        current_index++;
    }
    if (current_node == NULL) return FAILURE;

    list_node* new_node = (list_node *)malloc(sizeof(list_node));
    if (new_node == NULL) {
        printf("分配新节点失败.\n");
        free(new_node);
        return FAILURE;
    }
    new_node->data = insert_data;
    new_node->next = current_node->next;
    current_node->next = new_node;
    return SUCCESS;
}

/* 删除节点 -- 平均时间复杂度O(n) */
int delete_node(LINK_LIST list,int delete_index,elementType* delete_value) {
    if (delete_index < 1) {
        printf("非法索引.\n");
        return FAILURE;
    }
    list_node* current_node = list;
    int current_index = 0;
    while (current_node && current_index < delete_index - 1) {
        current_node = current_node->next;
        current_index++;
    }
    if (current_node == NULL) return FAILURE;

    list_node* temp_node = current_node->next;
    *delete_value = temp_node->data;
    current_node->next = temp_node->next;
    free(temp_node);
    return SUCCESS;
}

/* 按位查找元素 */
list_node* select_data_by_index(LINK_LIST list,const int select_index) {
    if (select_index < 1) {
        printf("非法索引.\n");
        return NULL;
    }
    list_node* current_node = list;
    int current_index = 0;
    while (current_node && current_index < select_index) {
        current_node = current_node->next;
        current_index++;
    }
    return current_node;
}

/* 按值查找元素 */
int select_data_by_value(LINK_LIST list,const elementType select_data) {
    list_node* current_node = list->next;
    int index = 1;
    while (current_node!= NULL && current_node->data != select_data) {
        current_node = current_node->next;
        index++;
    }
    if (current_node == NULL) return NOT_FOUND;
    return index;
}



/* 销毁链表 */
void destroy_list(LINK_LIST list) {
    list_node* current_node = list;
    list_node* temp_node = NULL;
    while (current_node != NULL) {
        temp_node = current_node;
        current_node = current_node->next;
        free(temp_node);
    }
    list = NULL;
}

/* 打印链表 */
void print_list(LINK_LIST list) {
    if (list == NULL) {
        printf("链表为空\n");
        return;
    }
    printf("完整链表为:\n[head]-->");
    list_node *current_node = list->next;   // 跳过头节点
    while (current_node != NULL) {
        printf("[%d]-->",current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}


int main() {

    LINK_LIST list = init_list();
    if (list == NULL) {
        printf("初始化失败,程序退出.");
        exit(EXIT_FAILURE);
    }
    for (int i = 0;i<10;i++) {
        insert_node(list,i+1,i*10);
    }
    print_list(list);

    elementType delete_value = 0;
    delete_node(list,3,&delete_value);
    printf("删除节点 value = [%d]\n",delete_value);
    print_list(list);

    printf("第3位元素为: %d\n",select_data_by_index(list,3)->data);

    printf("值为150的元素位于第%d位\n",select_data_by_value(list,150));

    destroy_list(list);
    return 0;
}


// Created by 柳贯一 on 2026/4/2.