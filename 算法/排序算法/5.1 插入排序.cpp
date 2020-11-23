#include<iostream>
#include <vector>

using namespace std;

/*
* 思路：当插入底i个对象时，前i-1个对象已经有序，
* 此时只需将底i项与前面i-1项进行比较，找到插入的位置，
* 移动该位置后面的元素，将该数据插入到该位置即可
* 
* 核心：找位置-->移位-->插入数据
*/

 //时间复杂度O(n^2)
void InsertSort(vector<int>& nums, int n)
{
	for (int i = 1;i <n;++i)  //i从1开始
	{
		//找到位置并进行移位
		int key = nums[i];
		int j = i - 1;
		for (;j >=0 && key<nums[j];--j)
		{
			nums[j + 1] = nums[j];
		}

		//插入数据
		nums[j + 1] = key;
	}
}


int main()
{
	vector<int> vec{ 5,3,4,2,1 };
	InsertSort(vec, vec.size());
	return 0;
}