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
	int e;
	printf("˳���L�е�����Ԫ�ذ��շǵݼ����С���дһ�㷨����e���뵽˳�����ʵ�λ���ϣ�ʹ�øñ���Ȼ���������ԡ�\n");
	for (item_num = 0; item_num < 5; item_num++){	//��ʼ��˳���
		list[item_num] = item_num * 2;
	}
	showList(list, item_num);
	printf("e: ");
	scanf_s("%d", &e);

	for (int i = 0, j = 0; i < item_num; i++, j++){
		if (j == item_num - 1){
			tempList[j] = list[i];
			j++;
			tempList[j] = e;
		}
		else if (list[i] < e || j != i){
			tempList[j] = list[i];
		}
		else{
			tempList[j] = e;
			j++;
			tempList[j] = list[i];
		}
	}
	showList(tempList, ++item_num);
	getch();

}