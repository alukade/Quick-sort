#include<stdio.h>

void quick_sort(int array[],int left,int right);

void quick_sort(int array[], int left, int right)
{
	int i = left;
	int j = right;
	int temp;//�������м����
	int pivot;//��׼��

	pivot = array[(left + right) / 2];//�����׼����ʵ�������ȡ������ȡ��������

	while (i <= j)
	{
		
		while (array[i] < pivot)//�������ҵ����ڵ��ڻ�׼���Ԫ��
		{
			i++;//�õ�Ȼ�׼��С���Ǿ������ƶ���i+1
		}
		/*��ߵ����Ȼ�׼����˳�whileѭ��*/

		while (array[j] > pivot)//���ҵ����ҵ�С�ڵ��ڻ�׼���Ԫ��
		{
			j--;//�õ�Ȼ�׼����Ǿ������ƶ���j-1
		}
		/*�ұߵ����Ȼ�׼��С���˳�ѭ��*/

		if (i <= j)//��������ͨ��while�ó����һ���������ұ�һ��С�������ڽ����ǵ�ֵ���н���
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
		/*i>jʱ����ʾһ�α���������������ʱ��߶��Ȼ�׼��С���ұ߶��Ȼ�׼���*/
	
	}
	if (left <j)//ֻҪjû����������ݹ�
	{
		quick_sort(array, left, j);//����j�����ݹ飬ֱ��j����left(�����)
	}
	if (i < right)//ֻҪiû�����Ҽ����ݹ�
	{
		quick_sort(array, i, right);//��i���Ҽ����ݹ飬֪��i�ﵽright(���ұ�)
	}

}


int main(void)
{
	int array[] = { 52,69,36,106,65,85,98,34,68,63,79,111,111,126,73,109 };
	int i, length;//�����i����forѭ�������ã��뺯���ڵ�i���ֿ���
	length = sizeof(array) / sizeof(array[0]);//�����ܿ�ȳ�ÿ������Ŀ��=�ܹ��ж��ٸ�Ԫ��
	quick_sort(array,0,length-1);//����˺��Ҷ˽��б���(�����һ���±���0�������Ҷ��±�Ϊlength-1)
	printf("�����Ľ���ǣ�");

	for (i = 0; i < length; i++)
	{
		printf(" %d", array[i]);
	}
	putchar('\n');//�����кÿ����
	putchar('\n');
	putchar('\n');

	return 0;
}