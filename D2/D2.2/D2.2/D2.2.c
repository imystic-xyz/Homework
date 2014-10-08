#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node, *Linklist;

Linklist createLinklist(){
	Node *L, *r, *p;
	//ElemType x;

	L = (Linklist)malloc(sizeof(Node));  //ͷ�ڵ�
	L->next = NULL;

	r = L;
	/*while (scanf("%d", &x) && x != 0)
	{
	p = (Linklist)malloc(sizeof(Node));
	p->data = x;
	r->next = p;
	r = p;
	}*/
	for (int i = 0; i < 15; i++){
		p = (Linklist)malloc(sizeof(Node));
		p->data = i;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return L;
}

void deleteLinklist(Linklist L){
	Node *p = L, *q;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
		q = NULL;
	}
}

Linklist selectLinklist(Linklist L, ElemType min, ElemType max){
	Node *p, *temp, *t;
	p = L->next;
	while (p != NULL && p->data < min){
		temp = p;
		p = p->next;
		free(temp);
	}
	L->next = p;
	while (p->next != NULL&& p->next->data <= max){
		p = p->next;
	}
	t = p->next;
	while (t != NULL){
		temp = t;
		t = t->next;
		free(temp);
	}
	p->next = NULL;
	return L;
}

void showLinklist(Linklist L){
	Node *p = L->next;
	printf("the lsit\n");
	while (p != NULL)
	{
		printf("-%d", p->data);
		p = p->next;
	}
	printf("\n");
}

main(){
	Linklist L;
	ElemType min, max;
	printf("��֪���Ա��е�Ԫ����ֵ�����������У����Ե��������洢�ṹ��\
		   		   		��дһ�㷨��ɾ����������ֵ����min��С��max������Ԫ��(�������������Ԫ��)��\
												ͬʱ�ͷű�ɾ�����Ŀռ䣬�������㷨��ʱ�临�Ӷȡ�(min��maxֵ�Լ���������)\n");
	L = createLinklist();
	showLinklist(L);
	printf("input the min and max\n");
	scanf_s("%d%d", &min, &max);
	L = selectLinklist(L, min, max);
	showLinklist(L);
	printf("�㷨���Ӷ�Ϊ n");
	getch();
}
