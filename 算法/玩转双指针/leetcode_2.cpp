#include <iostream>
#include<vector>

using namespace std;

//归并两个有序数组

/*88. 合并两个有序数组
* 
* 题目：
* 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

说明：
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例：
输入：
	nums1 = [1,2,3,0,0,0], m = 3
	nums2 = [2,5,6],       n = 3
输出：[1,2,2,3,5,6]

提示：
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1.length == m + n
nums2.length == n
* 
*/

/*
* 思路：类似归并排序的逻辑；
	首先数组nums1的大小是可以塞得下nums2的全部元素的（不需要考虑数组扩容），
	顺序执行的话，会把后面的数据覆盖掉，所以考虑倒序，从后向前比较大小，
	然后根据倒序的思维，找到合并后数组最后一个位置pos，从后向前放数据就行
*	
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	//特殊情况：nums1的size为空
	if (m == 0) 
		nums1 = nums2;

	int pos = n + m - 1;
	n--;
	m--;
	while (n >= 0)
	{
		//m < 0时，num2还没放完；
		//n < 0时，num1还没遍历完，但此时num1已经是放好了的！，这一点很细节
		nums1[pos--] = (m >= 0 && nums1[m] > nums2[n]) ? nums1[m--] : nums2[n--];
	}
}


int main()
{
	return 0;
}