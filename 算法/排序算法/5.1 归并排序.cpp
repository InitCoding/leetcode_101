#include<iostream>
#include <vector>

#define MAX_SIZE 1024
using namespace std;

//归并排序
/*
思路：
	分治的思想，分开治理；
	假设待排序序列长度为n，可以分别看成是n个长度为1的子序列，
	然后两两归并得到n/2个长度为2或1的有序子序列，
	如此循环，最终得到长度为n的有序序列的过程

	该排序方法也成为2路归并排序。
*/


//递归
//[,) 左闭右开
void MergeSort(vector<int>& nums, int left, int right,int* tmp)
{
	if (left + 1 >= right)
		return;
	//先进行拆分
	int mid = left + (right - left) / 2;
	MergeSort(nums, left, mid, tmp);
	MergeSort(nums, mid, right, tmp);

	int start1 = left, end1 = mid;
	int start2 = mid, end2 = right;
	int index = 0;  //tmp的下标

	//拆分后排序,合并
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

	//放回数据
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