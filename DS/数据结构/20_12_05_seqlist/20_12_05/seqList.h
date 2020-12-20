#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>  

//定义顺序表的结构
typedef int SLDataType;
//#define SLDataType int
typedef struct SeqList{
	SLDataType* a;
	size_t size;
	size_t capacity;
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);
void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps,SLDataType x); 
void SeqListPushFront(SeqList* ps,SLDataType x); 
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);
// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);