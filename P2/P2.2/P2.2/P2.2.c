#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node;

typedef struct{
	Node* LinkStack;
}LinkStack;

Node *createLinkStack(){
	Node *top;
	ElemType x;
	top = NULL;
	printf("Developed by\n¬���� ѧ�ţ�201307260111 & ���� ѧ�ţ�201307260124\n");
	printf("��ʼ��ջ�������ʼ������ 0 ����\n");
	while (scanf_s("%d", &x) && x != 0)
	{
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->data = x;
		temp->next = top;
		top = temp;
	}
	return top;
}

Node *push(Node *top, ElemType x){
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = x;
	temp->next = top;
	top = temp;
	return top;
}

ElemType *pop(Node ** top){
	ElemType x = (*top)->data;
	*top = (*top)->next;
	return  x;
}

void showLinkStack(Node *top){
	int length = 0;
	printf("now ,the link stack is:\n");
	while (top != NULL)
	{
		printf("|%3d |\n", top->data);
		top = top->next;
	}
}

main(){
	Node *top;
	ElemType x;
	top = createLinkStack();
	showLinkStack(top);
	printf("��ջ��");
	scanf_s("%d", &x);
	//��ջ
	top = push(top, x);
	showLinkStack(top);
	//��ջ
	printf("��ջ��%d\n", pop(&top));
	showLinkStack(top);
	getch();
}
