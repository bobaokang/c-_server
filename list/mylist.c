#include "mylist.h"

typedef struct PERSION
{
    char name[64];
    int age;
    int score;
}Persion;

// typedef void (*PrintLinkNode)(void *);// 打印函数指针
void IsNull(LinkList *list)
{
    if (list == NULL) {
        perror("LinkList *list is null");
        return;
    }
}
LinkList *InitList() // 初始化链表
{
    LinkList *list = (LinkList *)malloc(sizeof(LinkList));
    list->size = 0;
    list->head = (LinkNode *)malloc(sizeof(LinkNode));
    list->head->data = NULL;
    list->head->next = NULL;
    return list;
}
void InsetLinkList(LinkList *list, int pos, void *data) // 指定位置插入
{
    IsNull(list);
    if (data == NULL) {
        perror("data is null");
    }
    if ((pos < 0) || (pos > list->size)) {
        pos = list->size;
    }
    //创建新的节点
    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
    if (newNode == NULL) {
        FreeSpaceLinkList(list);
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    LinkNode *pCurrent = list->head;
    int i;
    for ( i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;
    list->size++;
    
}
void RemoveByPosLinkList(LinkList *list, int pos) // 删除指定位置的值
{
    IsNull(list);
    if ((pos < 0) || (pos > list->size)) {
        return;
    }
    LinkNode *pCurrent = list->head;
    int i;
    for ( i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    LinkNode *pDel = pCurrent->next;
    pCurrent->next = pDel->next;
    free(pDel);
    pDel = NULL;
    list->size --;
    
}
int SizeLinkList(LinkList *list) // 获取链表的长度
{
    IsNull(list);
    return list->size;
}
int FindLinkList(LinkList *list, void *data) // 查找
{
    IsNull(list);
    if (data == NULL) {
        perror("data is null");
        return -1;
    }
    LinkNode *pCurrent = list->head->next;
    int i;
    for (i = 0; i < list->size; i++) {
        if (pCurrent->data == data) {
            return i;
        }
        pCurrent = pCurrent->next;
    }
    return 0;
}
void *FrontLinkList(LinkList *list) // 返回第一个节点
{
    IsNull(list);
    return list->head->next->data;
}
void FreeSpaceLinkList(LinkList *list) // 释放内存
{
    IsNull(list);
    LinkNode *pCurrent = list->head;
    while (pCurrent != NULL) {
        LinkNode *pFree = pCurrent->next;
        free(pCurrent);
        pCurrent = pFree;
    }
    free(list);
    list = NULL;
}
void PrintLinkList(LinkList *list, PrintLinkNode print)
{
    IsNull(list);
    LinkNode *pCurrent = list->head->next;
    while (pCurrent != NULL) {
        print(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

void MyPrint(void *data)
{
    Persion *p = (Persion*)data;
    printf("name:%s age:%d score:%d\n", p->name, p->age, p->score);
}
int main(int argc, char const *argv[])
{
    LinkList *myList = InitList();
    Persion  p1 = {"aaa", 18, 66};
    Persion  p2 = {"bbb", 19, 78};
    Persion  p3 = {"ccc", 28, 43};
    Persion  p4 = {"ddd", 16, 89};
    Persion  p5 = {"eee", 21, 77};
    InsetLinkList(myList, 0, &p1);
    InsetLinkList(myList, 0, &p2);
    InsetLinkList(myList, 0, &p3);
    InsetLinkList(myList, 0, &p4);
    InsetLinkList(myList, 0, &p5);
    PrintLinkList(myList, MyPrint);
    printf("删除后\n");
    RemoveByPosLinkList(myList, 3);
    PrintLinkList(myList, MyPrint);

    printf("返回第一个节点\n");
    Persion *ret = (Persion *)FrontLinkList(myList);
    printf("name:%s age:%d score:%d\n", ret->name, ret->age, ret->score);

    FreeSpaceLinkList(myList);
    return 0;
}
