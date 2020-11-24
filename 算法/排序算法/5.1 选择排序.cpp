#include <iostream>
#include <vector>

using namespace std;

/*
* 思路：
* 每次从待排序中选出最小（或最大）的元素，放到起始位置，
* 一次按方法循环，直到将元素放到末尾，此时就是已序状态。
*/

//时间复杂度 O(n^2)
void SelectSort(vector<int>& nums, int n)
{
	for (int i = 0;i <n - 1; ++i)  //n-1防止j越界
	{
		int min = i;
		//找到元素最小的位置
		for (int j = i+1;j<n;++j)
		{
			if (nums[min] > nums[j])
				min = j;
		}
		//将最小的元素放在前面
		if (min != i)
			std::swap(nums[min], nums[i]);
	}
}


int main()
{
	vector<int> vec{ 1,5,3,6,4,2 };
	SelectSort(vec, vec.size());
	return 0;
}