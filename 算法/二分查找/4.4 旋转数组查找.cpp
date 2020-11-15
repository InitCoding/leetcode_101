#include<iostream>
#include<vector>

using namespace std;

//旋转数组查找
//81. 搜索旋转排序数组 II

/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:
输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true

示例 2:
输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
进阶:

这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
*/


/*
* 思路：
*	直接一个循环不就搞定了么。。。
*	用二分法来做试试：
*		重点是找到旋转的位置
*		分别在旋转位置左右两边用二分查找法（左右两边是已排序好的）
*		左边：
*			if (target < nums[mid] && target >= nums[left]) //target小于mid，则减小right缩小范围
				right = mid - 1;
			else
				left = mid + 1;
*		右边：
*			if (nums[mid] < target && target <= nums[right]) //tagrget大于mid，则增加left,缩小范围
				left = mid + 1;
			else
				right = mid - 1;
* 
*/

//二分法
bool search(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (left <=right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return true;
		
		//无法确定是否区间是增序的，只能移动left
		if (nums[mid] == nums[left])
			left++;
		else if (nums[mid] <= nums[right])  //右区间是增序的
		{
			if (nums[mid] < target && target <= nums[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
		else    //左区间是增序的
		{
			if (target < nums[mid] && target >= nums[left])
				right = mid - 1;
			else
				left = mid + 1;

		}
	}

	return false;
}


bool search1(vector<int>& nums, int target) {
	int start = 0, end = nums.size() - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (nums[mid] == target) {
			return true;
		}
		if (nums[start] == nums[mid])
		{
			// 无法判断哪个区间是增序的
			++start;
		}
		else if (nums[mid] <= nums[end])
		{
			// 右区间是增序的
			if (target > nums[mid] && target <= nums[end])
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		else
		{
			// 左区间是增序的
			if (target >= nums[start] && target < nums[mid]) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return false;
}

int main()
{
	vector<int> vec{3, 5, 1};
	bool ret = search1(vec, 1);
	bool ret0 = search(vec, 1);


	return 0;
}