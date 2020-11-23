#include<iostream>
#include <vector>

#define MAX_SIZE 1024
using namespace std;

//�鲢����
/*
˼·��
	���ε�˼�룬�ֿ�����
	������������г���Ϊn�����Էֱ𿴳���n������Ϊ1�������У�
	Ȼ�������鲢�õ�n/2������Ϊ2��1�����������У�
	���ѭ�������յõ�����Ϊn���������еĹ���

	�����򷽷�Ҳ��Ϊ2·�鲢����
*/


//�ݹ�
//[,) ����ҿ�
void MergeSort(vector<int>& nums, int left, int right,int* tmp)
{
	if (left + 1 >= right)
		return;
	//�Ƚ��в��
	int mid = left + (right - left) / 2;
	MergeSort(nums, left, mid, tmp);
	MergeSort(nums, mid, right, tmp);

	int start1 = left, end1 = mid;
	int start2 = mid, end2 = right;
	int index = 0;  //tmp���±�

	//��ֺ�����,�ϲ�
	while (start1<end1 && start2<end2)
	{
		if (nums[start1] < nums[start2])
			tmp[index++] = nums[start1++];
		else
			tmp[index++] = nums[start2++];
	}
	while (start1 < end1)
	{
		tmp[index++] = nums[start1++];
	}
	while (start2 < end2)
	{
		tmp[index++] = nums[start2++];
	}

	//�Ż�����
	for (int i = 0; i <index;++i)
	{
		nums[i + left] = tmp[i];
	}
}


int main()
{
	vector<int> vec = { 0,3,5,4,6,7,2,9,8,1 };
	int tmp[MAX_SIZE];
	MergeSort(vec, 0, vec.size(), tmp);
	return 0;
}