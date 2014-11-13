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
	ElemType x;

	L = (Linklist)malloc(sizeof(Node));  //头节点
	L->next = NULL;

	r = L;
	while (scanf_s("%d", &x) && x != 0)
	{
	p = (Linklist)malloc(sizeof(Node));
	p->data = x;
	r->next = p;
	r = p;
	}
	/*for (int i = 0; i < 15; i++){
		p = (Linklist)malloc(sizeof(Node));
		p->data = i;
		r->next = p;
		r = p;
	}*/
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

Linklist insertIntoList(Linklist L){ 
	Node *p, *t;
	Node *temp = (Linklist)malloc(sizeof(Node));
	ElemType x;
	scanf_s("%d", &x);
	temp->data = x;
	
	p = L->next;
	for (int i = 0; i < 2; i++){
		p = p->next;
	}
	t = p->next;
	p->next = temp;
	temp->next = t;
	return L;
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
	int length = 0;
	printf("the lsit\n");
	while (p != NULL)
	{
		printf("-%d", p->data);
		p = p->next;
		length++;
	}
	printf("\nthe length is %d\n", length);
}

main(){
	Linklist L;
	ElemType min, max;
	printf("试写一算法，将e插入到链表的第四个位置\n 请输入数据 以 数字 0 结束\n");
	L = createLinklist();
	showLinklist(L);
	//printf("input the min and max\n");
	//scanf_s("%d%d", &min, &max);
	//L = selectLinklist(L, min, max);
	L = insertIntoList(L);
	showLinklist(L);
	getch();
}
