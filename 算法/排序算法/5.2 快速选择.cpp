#include <iostream>
#include <vector>

using namespace std;

//快速选择

//leetcode
//215. 数组中的第K个最大元素
/*
* 在一个未排序的数组中，找到第 k 大的数字
*/

/*
* 思路：
*	利用快速排序的思想，我们只需要找到前面的k位就可以
*/

int PartSelection(vector<int>& nums, int left, int right)
{
	int start = left;
	int end = right;
	int key = nums[right];
	while (start<end)
	{
		while (start<end && nums[start] <= key)
			++start;
		while (start<end && nums[end] >= key)
			--end;
		std::swap(nums[start], nums[end]);
	}
	std::swap(nums[right], nums[end]);
	return end;
}

int findKthLargest(vector<int>& nums, int k)
{
	int left = 0;
	int right = nums.size() - 1;
	int target = nums.size() - k;  //第k大元素的下标
	while (left <right)
	{
		//每次找到划分的中间位置，进行比较
		int mid = PartSelection(nums, left, right);
		if (mid == target)
		{
			return nums[mid];
		}
		else if (mid < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return nums[left];
}





int main()
{
	vector<int> vec{ 3,2,1,6,5,0 };
	int number = findKthLargest(vec, 3);
	return 0;
}