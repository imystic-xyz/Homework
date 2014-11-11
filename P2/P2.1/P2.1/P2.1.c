#include<stdio.h>
#include<stdlib.h>
#define MAXLENGTH 10

typedef int ElemType;
typedef struct List
{
	ElemType stack[MAXLENGTH];
	int top;
}SeqStack;

SeqStack * init()
{	
	SeqStack *s;
	s = (SeqStack*)malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
	
}

ElemType getTop(SeqStack *s){
	if (s->top == -1){
		printf("/n空");
	}
	else
		return s->stack[s->top];
}
SeqStack *push(SeqStack *s, ElemType x){
	if (s->top == MAXLENGTH - 1){
		printf("/n stack full");
		return NULL;
	}
	else{
		s->top++;
		s->stack[s->top] = x;
		return s;
	}
}
ElemType get(SeqStack *s){
	if (s->top == -1){
		printf("stack empty");
		return NULL;
	}
	s->top--;
	return s->stack[s->top + 1];
}


void delete(SeqStack *s){
	s->top--;
}


void display(SeqStack *s){
	int t;
	t = s->top;
	printf("now the stack is:\n");
	while (t >= 0){
		printf("|%3d |\n", s->stack[t]);
		t--;
	}
	printf("the end\n\n");

}


main(){
	SeqStack *p;
	ElemType x;
	printf("Developed by\n卢贤泼 学号：201307260111 & 钟琪 学号：201307260124\n");
	p = init();
	for (int i = 1; i < 4; i++){
		push(p, i);
	}
	printf("init the seqStack:\n");
	display(p);
	printf("insert the x:");
	scanf_s("%d", &x);
	p = push(p, x);
	display(p);
	printf("获取 顶部元素:  %d\n", getTop(p));
	display(p);
	printf("删除元素\n");
	delete(p); 
	display(p);
	getch();
}