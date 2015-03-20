/* Program 04:
* Wenna Duan 02/27/2015
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100001

int check[1000] = { 0 };
int amount[MAX_SIZE] = { 0 };
int n;

int check_cashing(int deducted_amount){
	int i, j;

	amount[0] = 0;
	for (i = 1; i < deducted_amount; ++i)
		amount[i] = -1;

	for (i = 0; i < n; ++i)
	{
		for (j = deducted_amount; j > 0; --j)
			if (j >= check[i] && amount[j - check[i]] != -1)
				amount[j] = j - check[i];
	}
	if (amount[deducted_amount] != -1)
		return 1;
	else return 0;
}

void print_check_comb(int left_total){
	while (left_total > 0)
	{
		int c = left_total - amount[left_total];
		left_total = amount[left_total];
		printf_s("%d",c);
		if (left_total != 0)
			printf_s(", ");
	}
	printf_s("\n");
}

//int main()
//{
//	int i;
//	int deducted_amount;
//	scanf_s("%d", &deducted_amount);
//	scanf_s("%d", &n);
//
//	for (i = 0; i < n; ++i)
//		scanf_s("%d", &check[i]);
//	printf_s("\n");
//
//	int result = check_cashing(deducted_amount);
//	if (result == 1)
//		print_check_comb(deducted_amount);
//	else
//		printf_s("Not possible\n");
//	system("pause");
//}