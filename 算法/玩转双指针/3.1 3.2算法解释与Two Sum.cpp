﻿#include <iostream>
#include<vector>

using namespace std;

/*
# 算法解释
使用两个指针协同完成任务的方式，通常用于遍历数组，也可以延伸到多个数组的多个指针。
两个指针指向同一个数组，遍历方向相同且不相交，则这两个指针包含的区域称为** 滑动窗口** ，通常用于遍历区间搜索。
两个指针指向同一数组，遍历方向相反，则可以进行搜索，通常用来搜索已序数组。

# 理解
双指针更多的是解决问题的一种办法，个人觉得不能算严格意义上的算法。只是在某些情况下，更适用。
*/

//LeetCode案例
//167. Two Sum II - Input array is sorted (Easy)
/*
题目：
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
*/


//方法一：暴力求解   时间复杂度：O(n^2)
vector<int> twoSum_1(vector<int>& numbers, int target) 
{
	vector<int> vec;
	if (numbers.size() < 2)
		return vec;

	for (int i = 0; i < numbers.size() - 1; ++i)
	{
		for (int j = i + 1; j < numbers.size(); ++j)
		{
			if (numbers[i] + numbers[j] == target)
			{
				//i是下标从零开始的，实际返回的是第几个
				vec.push_back(i + 1);
				vec.push_back(j + 1);
				return vec;
			}
		}
	}

	return vec;
}


//双指针
/*
* 思路：
数组已经排好序，我们可以采用方向相反的双指针来寻找这两个数字，一个初始指向最
小的元素，即数组最左边，向右遍历；一个初始指向最大的元素，即数组最右边，向左遍历。
“也就是从两边到中间靠拢的策略”
*/
vector<int> twoSum_2(vector<int>& numbers, int target)
{
	int i = 0, j = numbers.size()-1;
	int sum = 0;
	while (i < j)
	{
		sum = numbers[i] + numbers[j];
		if(sum == target)
			break;

		//数组为升序
		if (sum > target)
			--j;
		else
			++i;
	}

	//返回的是第几个元素
	return vector<int>{i + 1, j + 1};
}



//int main()
//{
//	//[2 3 4]
//	std::vector<int> v{ 2,3,4 };
//	auto vec1 = twoSum_1(v, 6);
//	auto vec2 = twoSum_2(v, 6);
//
//	return 0;
//}