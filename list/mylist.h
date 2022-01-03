#ifndef LINK_LIST_H
#define LINK_LIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct LINKNODE
{
    void* data; // 指向任何类型的数据
    struct LINKNODE* next;
}LinkNode;

typedef struct LINKLIST
{
    LinkNode *head;
    int size;
}LinkList;

typedef void (*PrintLinkNode)(void *);// 打印函数指针

LinkList *InitList(); // 初始化链表
void InsetLinkList(LinkList *list, int pos, void *data); // 指定位置插入
void RemoveByPosLinkList(LinkList *list, int pos); // 删除指定位置的值
int SizeLinkList(LinkList *list); // 获取链表的长度
int FindLinkList(LinkList *list, void *data); // 查找
void *FrontLinkList(LinkList *list); // 返回第一个节点
void FreeSpaceLinkList(LinkList *list); // 释放内存
void PrintLinkList(LinkList *list, PrintLinkNode print);
#endif