#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>  

//����˳���Ľṹ
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
// ˳������
int SeqListFind(SeqList* ps, SLDataType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);