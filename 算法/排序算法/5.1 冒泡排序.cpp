#include <iostream>
#include <vector>

using namespace std;

/*
* 思路：
*	比较相邻的两个元素大小，调整位置直到没有元素需要交换，就是排序完成。
*/

//时间复杂度 O(n^2)
void BubbleSort(vector<int>& nums, int n)
{
	bool flag = false;  //是否已序
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0;j< n-i-1;++j)  //第j位和第j+1的位置比较
		{
			if (nums[j] > nums[j + 1])
			{
				flag = true;
				std::swap(nums[j], nums[j + 1]);
			}
		}
		if(!flag)
			break;
	}
}


int main()
{
	vector<int> vec{ 1,5,3,6,4,2 };
	BubbleSort(vec, vec.size());
	return 0;
}