/*********************************
    > File Name: quick_sort_randomNum.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年08月27日 星期四 17时27分08秒
 ********************************/
#include<stdio.h>
#include<time.h>
void swap(int *a, int *b);
void quick_sort(int *ary, int len);
int partition(int *ary, int len, int pivot_i);

int main(void)
{
	//从文件里读取随机数
	int i;
	int ary[100000] = {0};
	FILE *fread;
	fread = fopen("randomNum.txt", "r");
	for(i = 0; i < 100000; i++)
	{
		fscanf(fread, "%d", &ary[i]);//注意有&符号
	}
	//计算数组的长度
	int len = sizeof(ary)/sizeof(ary[0]);
	//进行排序
	clock_t bg, ed;
	bg = clock();
	quick_sort(ary,len);
	ed = clock();
	printf("cost time for : %.15f", (double)(ed - bg)/CLOCKS_PER_SEC);
	//将排序后的数组写入到文件中保存起来
	FILE *fwrite;
	fwrite = fopen("afterSort.txt","w");
	for(i = 0; i < 100000; i++)
	{
		fprintf(fwrite, "%d\t", ary[i]);
		if((i+1)%10 == 0)
			fprintf(fwrite, "%c", '\n');
	}
	printf("\n");

	//关闭文件描述符
	close(fread);
	close(fwrite);
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
	int pivot = ary[pivot_i];//以数组的第一个元素作为基准
	swap(&ary[pivot_i],&ary[pivot_i + (len - 1)]);//为何上来就交换首尾元素的位置
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


