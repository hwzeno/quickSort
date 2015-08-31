/*********************************
    > File Name: quick_sort_base.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年08月27日 星期四 17时27分08秒
 ********************************/
#include<stdio.h>
void swap(int *a, int *b);
void quick_sort(int *ary, int len);
int partition(int *ary, int len, int pivot_i);

int main(void)
{
	int i;
	int ary[] = {2, 4, 2, 5, 3, 5, 3, 1, 7, 6};
	int len = sizeof(ary)/sizeof(ary[0]);
	quick_sort(ary,len);
	for(i = 0; i < len; i++)
	{
		printf("%d ", ary[i]);
	}

	printf("\n");
	return 0;
}
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int partition(int *ary, int len, int pivot_i)
{
	int i = 0;
	int small_len = pivot_i;
	int pivot = ary[pivot_i];
	swap(&ary[pivot_i],&ary[pivot_i + (len - 1)]);
	for(; i < len; i++)
	{
		if(ary[pivot_i + i] < pivot)
		{
			swap(&ary[pivot_i + i], &ary[small_len]);
			small_len++;
		}
	}
	swap(&ary[pivot_i + len - 1], &ary[small_len]);
	return small_len;
}
void quick_sort(int *ary, int len)
{
	if(len == 0 || len == 1)
		return ;
	int small_len = partition(ary, len, 0);
	quick_sort(ary, small_len);
	quick_sort(&ary[small_len + 1], len - small_len - 1);
}


