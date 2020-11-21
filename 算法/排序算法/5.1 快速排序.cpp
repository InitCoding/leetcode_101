#include<iostream>
#include <vector>
#include <stack>

using namespace std;

//快速排序
/*
思路：
	分治的思想，分开治理；
	用某个数据作为key,把大于key和小于key的分成两边（大于key在右边，小于key在左边）
	将这两边分别作为子数组继续划分，直到区间只有一个值（此时就是有序的）
*/


//快速排序【递归】
void quickSort(vector<int>& nums, int left, int right)
{
	if (left + 1 >= right)
		return;

	int first = left;
	int last = right;
	int key = nums[last];  //此处选用last元素为key
	while (first < last)
	{
		while (first<last && nums[first]<=key)
		{
			first++;
		}
		//填坑法
		if(first<last)
			nums[last] = nums[first];

		while (first<last && nums[last] >=key)
		{
			last--;
		}
		if(first < last)
			nums[first] = nums[last];
	}
	nums[last] = key;  //填坑法需要将key放回去
	quickSort(nums, left, first - 1);   //注意边界的控制
	quickSort(nums, first + 1, right);
}


//快速排序【循环】
int PartSort(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		int key = nums[right];
		while (left<right)
		{
			while (left<right && nums[left] <= key)
				left++;
			if (left < right)
				nums[right--] = nums[left];

			while (left <right && nums[right] >= key)
				right--;
			if (left < right)
				nums[left++] = nums[right];
		}
		nums[right] = key;
	}
	return right;
}
void quickSort1(vector<int>& nums, int left, int right) 
{
	if (left + 1 < right)
	{
		stack<int> s;
		int boundary = PartSort(nums, left, right);
		if (boundary - 1 > left)
		{
			s.push(left);
			s.push(boundary - 1);
		}
		if (boundary + 1 < right)
		{
			s.push(boundary + 1);
			s.push(right);
		}

		while (!s.empty())
		{
			int end = s.top();
			s.pop();
			int start = s.top();
			s.pop();
			
			boundary = PartSort(nums, start, end);
			if (boundary - 1 > start)
			{
				s.push(start);
				s.push(boundary - 1);
			}
			if (boundary + 1 < end)
			{
				s.push(boundary + 1);
				s.push(end);
			}
		}
	}

}


int main()
{
	vector<int> vec{ 5,3,1,6,4,2};
	quickSort1(vec, 0, vec.size() - 1);
	return 0;
}