#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100000

int data[MAX_SIZE];

void swap(int*a, int*b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void generate_data(int* data, int n)
{
	srand((int)time(0));

	for (int i = 0; i < n; ++i)
	{
		data[i] = i;
	}

	for (int i = n - 1; --i; i >=0)
	{
		int j = rand() % (i+1);
		swap(&data[i], &data[j]);
	}
}

void display_data(int* data, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}

void heap_up(int index)
{

}

void heap_down(int* data, int n, int index)
{
	int l, r, max;


	while (index < n/2)
	{
		l = 2 * index + 1;
		r = 2 * index + 2;

		if (r < n && data[r] > data[l])
			max = r;
		else
			max = l;
		if (data[max] > data[index])
		{
			swap(&data[index], &data[max]);
			index = max;
		}
		else
			break;
	}
}

void build_heap(int* data, int n)
{
	for (int i = n / 2; i >= 0; --i)
	{
		heap_down(data, n, i);
	}
}

void head_sort(int* data, int n)
{
	build_heap(data, n);
	for (int i = n - 1; i > 0; --i)
	{
		swap(&data[0], &data[i]);
		heap_down(data, i, 0);
	}
}

//int main()
//{
//	int n = 15;
//	generate_data(data, n);
//	display_data(data, n);
//
//	head_sort(data, n);
//	display_data(data, n);
//	system("pause");
//}