#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct stack {
    int array[100];
	int top;//ջ��
}Stack;
//֧�ֶ�̬������ջ

void Stackinit(stack *s)
{
	s->top = 0;
}
void StackPush(Stack* s, int val) {
	s->array[s->top++];//ѹջ,β��
}
//��ջ
int StackPop(Stack* s) {
	assert(s->top > 0);
	return s->array[--s->top];
}
//�鿴ջ��Ԫ��
int StackTop(stack* s) {
	assert(s->top > 0);
	return s->array[s->top - 1];
}
//ͳ��ջ��Ԫ��
int StackSize(Stack* s) {
	return s->top;
}
//�ж�ջ���Ƿ�Ϊ��
int StackIsEmpty(Stack* s) {
	return s->top == 0 ? 1 : 0;
}
//��ҵ1����˳���ʵ��ջ
//2)������ʵ��ջ
//˳���ʵ��ջ

//��˳���ʵ��ջ
typedef struct Seqstack {
	int* array;//���ٶ�ָ̬�������(int���ͺ������Ϳ��ٵ�������ʲô���𣿣���
	int size;
	int capacity;
}Seqstack;
//ѹջ
void SeqStackPush(Seqstack*s, int val) {
	//�������ݵ�����
	if (s->size >= s->capacity) {
		int* newcapacity = (int*)malloc(sizeof(int)*s->capacity*2);
		for (int i = 0; i < s->size; i++) {
			newcapacity[i] = s->array[i];
		}
		free(s->array);
		s->array = newcapacity;
	}
	s->array[s->size] = val;
	s->size++;
}

//��ջ
void SeqStackPop(Seqstack* s)//βɾ
{
	assert(s->size != 0);
	s->array[s->size--];
}
//�鿴ջ��Ԫ��
int SeqStackTop(Seqstack* s) {
	//����˳���ĩβ
	assert(s->size != 0);
	return s->array[s->size - 1];
}
//ͳ��ջ��Ԫ��
int SeqStackSize(Seqstack* s) {
	return s->size;
}
//�ж�ջ���Ƿ�Ϊ��
int SeqStackIsEmpty(Seqstack* s) {
	return s->size == 0 ? 1: 0;
}


//����ʵ��ջ
//Ϊ��ʵ�ָ��Ӷ�ΪO��1�����ҷ�����ҵ�
//ĩβԪ��������˫�򲻴�ͷ��ѭ������
typedef struct Stacklist {
	struct Stacklist* next;
	struct Stacklist* prev;
	int val;
}Stacklist;
//��ʼ��
Stacklist* initial(Stacklist* s) {
	Stacklist* node = NULL;
	node->next = node;
}
//ѹջ
void Stacklistpush(Stacklist*s,int val){
  //β��
	Stacklist* Node = (Stacklist*)malloc(sizeof(Stacklist));
	Node->val = val;
	if (s == NULL) {
		Node->next = s;
		s = Node;
	}
	else {
		while (s != NULL) {
			s = s->next;
		}
		Stacklist* last = s;
		last->next = Node;
	}
	Node->next = NULL;
}
//��ջ
void Stacklistpush(Stacklist* s) {
	assert(s != NULL);
	while (s->next != NULL) {
		s = s->next;
	}
	free(s);
}
//�鿴ջ��Ԫ��
int Stacklisttop(Stacklist * s) {
	//����˳���ĩβ
	assert(s != NULL);
	while (s != NULL) {
		s = s->next;
	}
	return s->val;
}
