// 算法解释：
/*
	二分查找也称为折半查找，每次将查找区间分成两部分只取其中一部分，将查找的复杂度大大降低。
	对于一个长度为O(n)的数组，二分查找的时间复杂度为O(log n)
* /


/*
题目：
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:
输入: 4
输出 : 2

示例 2 :
	输入 : 8
	输出 : 2

说明 : 8 的平方根是 2.82842...,
	由于返回类型是整数，小数部分将被舍去。
*/

int mySqrt(int x) 
{
	if (x == 0)
		return x;

	int left = 0;
	int right = x;
	long mid  = 0;
	int sqrt = 0;
	while (right >= left)
	{
		mid = (left + right) >> 1;
		sqrt = x / mid;  // sqrt所在范围内查找
		if (mid == sqrt)
			return mid;
		else if (sqrt < mid)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return right;
}

int main()
{
	//int a = mySqrt(8);
	//int a = mySqrt(2);
	int a = mySqrt(6);
	return 0;
}
