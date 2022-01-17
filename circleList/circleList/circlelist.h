#ifndef LINK_CIRCLE_LIST_H
#define LINK_CIRCLE_LIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct STRUCTCIRCLENODE {
    struct STRUCTCIRCLENODE *next;
} CircleNode;
typedef struct STRUCTCIRCLELIST {
    CircleNode head;
    int size;
} CircleList;

typedef int(* CompareNodeCallBack)(CircleNode *, CircleNode *);
typedef void(* PrintNodeCallBack)(CircleNode *);
//初始化
CircleList *InitCircleList();
//插入
void InsetCircleList(CircleList *cList, int pos, CircleNode *cNode);
//返回第一个元素
CircleNode *FrontCircleList(CircleList *cList);
//根据位置删除
void RemoveByPosCircleList(CircleList *cList, int pos);
//根据值删除
void RemoveByDataCircleList(CircleList *cList, CircleNode *cNode, CompareNodeCallBack compareNodeCallBack);
//获取链表长度
int SizeofCircleList(CircleList *cList);
//查找
int FindCircleList(CircleList *cList, CircleNode *cNode, CompareNodeCallBack compareNodeCallBack);
//打印
int PrintCircleList(CircleList *cList, PrintNodeCallBack printNodeCallBack);
//释放
void FreeCircleList(CircleList *cList);
//判空
void IsNull(CircleList *cList);
#endif