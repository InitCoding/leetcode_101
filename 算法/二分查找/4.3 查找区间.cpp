#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

//查找区间
//34 Find First and Last Position of Element in Sorted Array (Medium)
/*
题目：
	给定一个增序的整数数组和一个值，查找该值第一次和最后一次出现的位置。

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]

示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
*/

/*
思路：
	找第一次出现的位置：
		nums[i]==target && 上一个元素不等于target
		等于等于target时，不断缩小区间的上限，才能根据二分法找到第一次出现的位置

	找到最后一次出现的位置：
		nums[i]==target && 下一个元素不等于target
		大于target才能缩小上限，否则不断区间增加下限，才能确定是最后一次出现的位置

	！特别注意：边界问题的考虑，防止数组越界
*/


//找最小的位置
int findFirst(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return -1;

	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (right >= left)
	{
		mid = (left + right) >> 1;
		if ( nums[mid] == target && (mid - 1 < 0 || nums[mid - 1] != target) )  //第一个位置 或者 上一个元素不是target
			return mid;
		else if(nums[mid] >= target)  //此处需要缩小右边界范围，从等于target开始就缩小
			right = mid - 1;
		else
			left = mid + 1;
	}

	return -1;
}

//找最大的位置
int findLast(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return -1;

	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (right >= left)
	{
		mid = (left + right) >> 1;
		if (nums[mid] == target && (mid + 1 >= nums.size() || nums[mid+1] != target)) //已经排查到最后一个元素 或者 下一个元素不为target
			return mid;
		else if (nums[mid] > target) //此处不能有等于，必须大于target才能将区间的右边界缩小
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}


vector<int> searchRange(vector<int>& nums, int target)
{
	 return vector<int>{findFirst(nums, target), findLast(nums, target)};
}


int main()
{
	//vector<int> v{ 5,7,7,8,8,10 };
	//auto vec = searchRange(v, 8);

	//auto vec2 = searchRange(v,6);

	vector<int> v1{ 2,2 };
	auto vec1 = searchRange(v1, 2);



	return 0;
}
