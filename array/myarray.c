#include "myarray.h"
void IsNull(DynamicArray *arry)
{
    if (arry == NULL) {
       printf("arry = NULL\n");
    }
}

// 初始化
DynamicArray *InitArry(int capacity)
{
    DynamicArray *initAddr = (DynamicArray *)malloc(sizeof(DynamicArray));
    IsNull(initAddr);
    initAddr->size = 0;
    initAddr->capacity = capacity;
    initAddr ->pAddr = (int *)malloc(sizeof(int) * initAddr->capacity);
    return initAddr;
};
// 增加
int PushBackArry(DynamicArray *arry, int value)
{
    IsNull(arry);
    if (arry->size == arry->capacity) {
        printf("当前内存大小为：[%d]太小，扩展为:%d\n", arry->capacity, arry->capacity * 2);
        int *newSpace = (int *)malloc(sizeof(int) * (arry->capacity) * 2);
        if (newSpace == NULL) {
            perror("malloc erro");
            FreeSpaceArry(arry);
            return -1;
        }
        memcpy(newSpace, arry->pAddr, arry->capacity * sizeof(int));
        if (arry->pAddr != NULL) {
            printf("清除之前的内存\n");
            free(arry->pAddr);
        }
        arry->capacity = arry->capacity * 2;
        arry->pAddr = newSpace;
    }
    printf("增加元素:[%d],位置:[%d]\n",value, arry->size);
    arry->pAddr[arry->size] = value;
    arry->size ++;
    return 0;
}

// 通过位置删除
int RemoveByPosArry(DynamicArray *arry, int pos)
{
    IsNull(arry);
    if ((pos >= arry->size) || (pos < 0)) {
        FreeSpaceArry(arry);
        return -1;
    }
    int i;
    for (i = pos; i < arry->size - 1; i++) {
        arry->pAddr[i] = arry->pAddr[i + 1];
    }
    arry->size--;    
    return 0;
}
// 通过值得到位置
int GetposByValueArry(DynamicArray *arry, int value)
{
    IsNull(arry);
    int i;
    for (i = 0; i < arry->size; i++) {
        if (arry->pAddr[i] == value)
        {
            return i;
            break;
        }
    }
    printf("not find:%d", value);    
    return -1;
}

// 通过值删除
int RemoveByValueArry(DynamicArray *arry, int value)
{
    IsNull(arry);
    return RemoveByPosArry(arry, GetposByValueArry(arry, value));
}

// 通过位置得到值
int GetValueByposArry(DynamicArray *arry, int pos)
{
    IsNull(arry);
    return arry->pAddr[pos];
}


// 得到当前有几个元素
int GetSizeArry(DynamicArray *arry)
{
    IsNull(arry);
    return arry->size;
}
// 得到容量大小
int GetCapacityArry(DynamicArray *arry)
{
    IsNull(arry);
    return arry->capacity;
}

// 打印数组
void PrintArry(DynamicArray *arry)
{
    IsNull(arry);
    int i = 0;
    for (i = 0; i < arry->size; i++)
    {
        printf("%d ", arry->pAddr[i]);
    }
    printf("\n");
}

// 清空数组
void CleanUpArry(DynamicArray *arry)
{
    IsNull(arry);
    arry->size = 0;
}
// 清空内存
int FreeSpaceArry(DynamicArray *arry)
{
    IsNull(arry);
    if (arry->pAddr != NULL) {
        free(arry->pAddr);
        arry->pAddr = NULL;
    }
    free(arry);
    arry = NULL;
    return 0;
}
int main(int argc, char const *argv[])
{
    DynamicArray *testArry = InitArry(6);
    int i;
    for ( i = 100; i < 110; i++) {
        PushBackArry(testArry, i);
    }
    PrintArry(testArry); // 打印
    int ret = GetposByValueArry(testArry, 109);
    printf("通过值得到位置:%d\n", ret);

    ret = GetSizeArry(testArry);
    printf("存在于动态数组的元素个数:%d\n", ret);
    
    ret = GetCapacityArry(testArry);
    printf("当前动态数组共能存储元素的个数:%d \n", ret);

    RemoveByValueArry(testArry, 100); // 通过值删除
    PrintArry(testArry);

    ret = GetSizeArry(testArry);
    printf("存在于动态数组的元素个数:%d\n", ret);
    
    ret = GetCapacityArry(testArry);
    printf("当前动态数组共能存储元素的个数:%d \n", ret);

    RemoveByPosArry(testArry, 6);
    PrintArry(testArry);

    ret = GetValueByposArry(testArry, 6);
    printf("位置为6的数据大小为:%d \n", ret);

    CleanUpArry(testArry);
    PrintArry(testArry);

    FreeSpaceArry(testArry);
    return 0;
}
