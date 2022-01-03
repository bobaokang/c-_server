#ifndef MY_ARRAY
#define MY_ARRAY
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct MyArray
{
    int *pAddr; // 存放数据的指针
    int size; // 当前有多少元素
    int capacity; // 容量

}DynamicArray;

DynamicArray *InitArry(int capacity); // 初始化
int PushBackArry(DynamicArray *arry, int value); // 插入
int RemoveByPosArry(DynamicArray *arry, int pos); // 根据位置删除
int RemoveByValueArry(DynamicArray *arry, int value); // 根据值删除
int FindValueArry(DynamicArray *arry, int value); // 查找
int FreeSpaceArry(DynamicArray *arry); // 清除
int GetSizeArry(DynamicArray *arry); // 获取当前元素个数
int GetValueByposArry(DynamicArray *arry, int pos); // 根据位置返回值
void PrintArry(DynamicArray *arry); //打印
void CleanUpArry(DynamicArray *arry); // 清空数组
int GetCapacityArry(DynamicArray *arry); // 得到动态数组容量
#endif
