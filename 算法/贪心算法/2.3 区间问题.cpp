#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

//区间问题
//435. Non-overlapping Intervals (Medium)
/*
题目描述：
	给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。

输入输出样例：
	输入是一个数组，数组由多个长度固定为 2 的数组组成，表示区间的开始和结尾。输出一个
整数，表示需要移除的区间数量。

Input : [[1, 2], [2, 4], [1, 3]]
Output : 1

在这个样例中，我们可以移除区间[1, 3]，使得剩余的区间 [[1, 2], [2, 4]] 互不重叠。
*/


//比较器
bool comparator(const vector<int>& a, const vector<int>& b)
{
	if (a.size() < 2 || b.size() < 2)
		return (a[0] < b[0]);
	
	return (a[1] < b[1]);
}


//时间复杂度：O(n)
int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
	//先处理特殊情况
	if (intervals.size() < 2)
		return 0;

	//排序方便对比大小(以空间结尾作为对比值)
	//std::sort(intervals.begin(), intervals.end(), comparator);//比较器
	
	std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
		{
			if (a.size() < 2 || b.size() < 2)
				return (a[0] < b[0]);
			return (a[1] < b[1]);
		}); //正则表达式

	//根据边界值进行对比，确认是否重叠
	int count = 0;
	int lastBoundary = intervals[0][1];   //初始值为边界起点
	for (int i = 0; i < intervals.size() - 1; ++i)	//注意控住边界条件 i的取值范围
	{
		if (lastBoundary > intervals[i + 1][0])  //重叠条件：上一个空间的末尾大于下一个空间的初始值
			++count;
		else
			lastBoundary = intervals[i+1][1];	//不满足条件则更新边界
	}

	return count;
}

