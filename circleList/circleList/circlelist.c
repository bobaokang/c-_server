#include "circlelist.h"
void IsNull(CircleList *cList)
{
    if(cList == NULL){
        perror("cList is null");
        return ;
    }
}
//初始化
CircleList *InitCircleList()
{
    CircleList *circleList = (CircleList *)malloc(sizeof(CircleList));
    IsNull(circleList);
    circleList->head.next = &(circleList->head);
    circleList->size = 0;
    return circleList;
}
//插入
void InsetCircleList(CircleList *cList, int pos, CircleNode *cNode)
{
    IsNull(cList);
    if (cNode == NULL) {
        perror(" cNode is NULL");
        return;
    }
    if (pos < 0 || pos > cList->size) {
        pos = cList->size;
    }
    CircleNode *pCurrect = &(cList->head);
    int i;
    for (i = 0; i < cList->size; i++) {
        pCurrect = pCurrect->next;
    }
    cNode->next = pCurrect->next;
    pCurrect->next = cNode;
    cList->size ++;

}
//返回第一个元素
CircleNode *FrontCircleList(CircleList *cList)
{
    return cList->head.next;
}
//根据位置删除
void RemoveByPosCircleList(CircleList *cList, int pos)
{
    IsNull(cList);
    if (pos < 0 || pos >= cList->size) {
        return;
    }
    CircleNode *pCurrect = &(cList->head);
    int i;
    for (i = 0; i < pos; i++) {
        pCurrect = pCurrect->next;
    }
    CircleNode *pNext = pCurrect->next;
    pCurrect->next = pNext->next;
    pNext = NULL;
    cList->size --;
}

//根据值删除
void RemoveByDataCircleList(CircleList *cList, CircleNode *cNode, CompareNodeCallBack compareNodeCallBack)
{
    IsNull(cList);
    if (cNode == NULL) {
        perror(" cNode is NULL");
        return;
    }
    CircleNode *pPrev = &(cList->head);
    CircleNode *pCurrect = pPrev->next;
    int i;
    for (i = 0; i < cList->size; i++) {
       if(compareNodeCallBack(pCurrect, cNode) == 0) {
           pPrev->next = pCurrect->next;
           break;
       }
       pPrev = pCurrect;
       pCurrect = pPrev->next;
    }
    cList->size --;
}

//获取链表长度
int SizeofCircleList(CircleList *cList) {
    return cList->size;
}
//查找
int FindCircleList(CircleList *cList, CircleNode *cNode, CompareNodeCallBack compareNodeCallBack)
{
    IsNull(cList);
    if (cNode == NULL) {
        perror(" cNode is NULL");
        return -1;
    }
    CircleNode *pCurrect = cList->head.next;
    int i;
    int flag = -1;
    for (i = 0; i < cList->size; i++) {
        if(compareNodeCallBack(pCurrect, cNode) == 0) {
            printf("被找到:%d\n", cList->size);
            flag = i;
            break;
        }
        pCurrect = pCurrect->next; 
    }
    return flag;
}

int PrintCircleList(CircleList *cList, PrintNodeCallBack printNodeCallBack)
{
    IsNull(cList);
    CircleNode *pCurrect = cList->head.next;
    int i;
    for (i = 0; i < cList->size; i++) {
        printNodeCallBack(pCurrect);
        pCurrect = pCurrect->next; 
    }
    return 0;
}
//释放
void FreeCircleList(CircleList *cList)
{
    IsNull(cList);
    free(cList);
    cList = NULL;
}


typedef  struct PERSION {
    CircleNode cNode;
    int age;
    char name[64];
} Persion;

 void PrintNode(CircleNode *cNode)
 {
    Persion *p = (Persion *)cNode;
    printf("name:%s, age:%d\n", p->name, p->age);
 }
int CompareNode(CircleNode *cNode1, CircleNode *cNode2)
{
    Persion *p1 = (Persion *)cNode1;
    Persion *p2 = (Persion *)cNode2;
    if ((p1->age == p2->age) && (strcmp(p1->name, p2->name) == 0)) {
        return 0;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    CircleList *cList = InitCircleList();
    Persion p1, p2, p3, p4, p5;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");
    p1.age = 11;
    p2.age = 21;
    p3.age = 31;
    p4.age = 41;
    p5.age = 51;

    InsetCircleList(cList, 0, (CircleNode *)&p1);
    InsetCircleList(cList, 0, (CircleNode *)&p2);
    InsetCircleList(cList, 0, (CircleNode *)&p3);
    InsetCircleList(cList, 0, (CircleNode *)&p4);
    InsetCircleList(cList, 0, (CircleNode *)&p5);
    printf("-----------------打印---------------------\n");
    PrintCircleList(cList, PrintNode);
    
    printf("-----------------根据位置删除---------------------\n");
    RemoveByPosCircleList(cList, 2);
    PrintCircleList(cList, PrintNode);

    printf("-----------------根据数据删除---------------------\n");
    Persion pDel;
    strcpy(pDel.name, "ddd");
    pDel.age = 41;
    RemoveByDataCircleList(cList, (CircleNode *)&pDel, CompareNode);
    PrintCircleList(cList, PrintNode);

    return 0;
}
