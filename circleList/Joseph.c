#include "circlelist.h"
typedef struct Joseph
{
    CircleNode cNode;
    int val;
} MyNum;

#define M 8
#define N 3
int CompareNode(CircleNode *cNode1, CircleNode *cNode2)
{
    MyNum *p1 = (MyNum *)cNode1;
    MyNum *p2 = (MyNum *)cNode2;
    if (p1->val == p2->val) {
        return 0;
    }
    return -1;
}

void PrintNode(CircleNode *cNode)
{
    MyNum *p = (MyNum *)cNode;
    printf("%d\t", p->val);
}

int main(int argc, char const *argv[])
{
    CircleList *cList = InitCircleList();
    MyNum num[M];
    int i;
    for (i = 0; i < M; i++) {
        num[i].val = i + 1;
        InsetCircleList(cList, i, (CircleNode *)&num[i]);
    }
    PrintCircleList(cList, PrintNode);
    printf("\n");
    int index = 1;
    CircleNode *pCurrent = cList->head.next;
    while (SizeofCircleList(cList) > 1) {
        if (index == N) {
            MyNum *testTmp = (MyNum *)pCurrent;
            printf("%d\t", testTmp->val);
            //缓存待删除的节点的下一个节点
            CircleNode *pNextNode = pCurrent->next;
            RemoveByDataCircleList(cList, pCurrent, CompareNode);
            pCurrent = pNextNode;
            if (pCurrent == &(cList->head)) {
                pCurrent = pCurrent->next;
            }
            index = 1;
        }
        pCurrent = pCurrent->next;
        if (pCurrent == &(cList->head)) {
            pCurrent = pCurrent->next;
        }
        index ++;
    }
    if (SizeofCircleList(cList) == 1) {
        MyNum *frontNode = (MyNum *)FrontCircleList(cList);
        printf("%d\n", frontNode->val);
    } else {
        printf("erro\n");
    }
    
    FreeCircleList(cList);
    return 0;
}
// 1       2       3       4       5       6       7       8
// 3       6       1       5       2       8       4       7