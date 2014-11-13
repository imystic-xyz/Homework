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

	L = (Linklist)malloc(sizeof(Node));  //头节点
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
	printf("已知线性表中的元素以值递增有序排列，并以单链表做存储结构。\
		   		   		试写一算法，删除表中所有值大于min且小于max的数据元素(假设存在这样的元素)，\
												同时释放被删除结点的空间，并分析算法的时间复杂度。(min和max值自己给定即可)\n");
	L = createLinklist();
	showLinklist(L);
	printf("input the min and max\n");
	scanf_s("%d%d", &min, &max);
	L = selectLinklist(L, min, max);
	showLinklist(L);
	printf("算法复杂度为 n");
	getch();
}
