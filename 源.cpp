#include<stdio.h>

void quick_sort(int array[],int left,int right);

void quick_sort(int array[], int left, int right)
{
	int i = left;
	int j = right;
	int temp;//互换的中间变量
	int pivot;//基准点

	pivot = array[(left + right) / 2];//这里基准点其实可以随便取，这里取数组中心

	while (i <= j)
	{
		
		while (array[i] < pivot)//从左到右找到大于等于基准点的元素
		{
			i++;//该点比基准点小，那就向右移动，i+1
		}
		/*左边的数比基准点大，退出while循环*/

		while (array[j] > pivot)//从右到左找到小于等于基准点的元素
		{
			j--;//该点比基准点大，那就想左移动，j-1
		}
		/*右边的数比基准点小，退出循环*/

		if (i <= j)//上面两段通过while得出左边一个大数，右边一个小数，现在将他们的值进行交换
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
		/*i>j时，表示一次遍历函数结束，此时左边都比基准点小，右边都比基准点大*/
	
	}
	if (left <j)//只要j没到最左继续递归
	{
		quick_sort(array, left, j);//从左到j继续递归，直到j到达left(最左边)
	}
	if (i < right)//只要i没到最右继续递归
	{
		quick_sort(array, i, right);//从i到右继续递归，知道i达到right(最右边)
	}

}


int main(void)
{
	int array[] = { 52,69,36,106,65,85,98,34,68,63,79,111,111,126,73,109 };
	int i, length;//这里的i仅作for循环计数用，与函数内的i区分开！
	length = sizeof(array) / sizeof(array[0]);//数组总宽度除每个数组的宽度=总共有多少个元素
	quick_sort(array,0,length-1);//从左端和右端进行遍历(数组第一个下标是0，故最右端下标为length-1)
	printf("排序后的结果是：");

	for (i = 0; i < length; i++)
	{
		printf(" %d", array[i]);
	}
	putchar('\n');//换个行好看点哈
	putchar('\n');
	putchar('\n');

	return 0;
}