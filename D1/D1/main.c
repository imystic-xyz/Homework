#include<stdio.h>
#define itemNum 3    //set the length of numArry 

int fun_exchangeNum(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 1;
}

int main(){
	int numArr[itemNum];
	printf("this is for des order \ninput three num: ");
	for (int i = 0; i < itemNum; i++){
		scanf("%d", &numArr[i]);
	}

	//bubble sort
	for (int i = 0; i < itemNum - 1; i++){
		for (int j = itemNum - 1; j > i; j--){
			if (numArr[j] > numArr[j - 1])     // > desc	< asce
				fun_exchangeNum(&numArr[j], &numArr[j - 1]);
		}
	}

	for (int i = 0; i < itemNum; i++)
		printf("%d ", numArr[i]);

	system("pause");
}