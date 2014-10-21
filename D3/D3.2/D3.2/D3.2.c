#include<stdio.h>

void test(int *sum){
	int x;

	scanf_s("%d", &x);
	if (x == 0) *sum = 0;
	else{
		test(sum);
		*sum += x;
	}
	printf("%d-", *sum);
}

void noRecursion(int *sum){
	int temp[20];
	int i = 0;
	int x;
	while (i <= 20 && temp[i-1] != 0){
		scanf_s("%d", &temp[i]);
		i++;
	}
	i--;
	while (i >= 0){
		*sum += temp[i];
		i--;
		printf("%d-", *sum);
	}
}
main(){
	int sum = 0;
	test(&sum);
	printf("\n another way\n");
	sum = 0;
	noRecursion(&sum);
	getch();
}