#include<stdio.h>
#define MAXLENGTH 10

void showList(int *list, int length){
	printf("the list\n");
	for (int i = 0; i < length; i++){
		printf("%d - ", list[i]);
	}
	printf("\n");
}


main(){
	int list[MAXLENGTH];
	int tempList[MAXLENGTH];
	int item_num = 0;
	int e,x,temp;
	printf("试写一算法，将e插入到顺序表的第四个位置\n请输入5个数字：");
	for (item_num = 0; item_num < 5; item_num++){	//初始化顺序表
		scanf_s("%d", &x);
		list[item_num] = x;
	}
	showList(list, item_num);
	printf("The length of list is %d\n", item_num);
	printf("The third item is %d\n", list[2]);
	printf("Insert item at the forth item x: ");
	scanf_s("%d", &e);

	for (int i = 0, j = 0; i < item_num; i++, j++){
		if (i != 3 ){
			tempList[j] = list[i];
		}
		else if (i = 3 ){
			tempList[j] = e;
			j++;
			tempList[j] = list[i];

		}
		else{
			printf("wrong");
		}
	}
	showList(tempList, ++item_num);
	printf("the length is %d", item_num);
	getch();
}