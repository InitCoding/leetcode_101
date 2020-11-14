#include <iostream>
#include<map>

using namespace std;

//633. 平方数之和
/*
* 76. 最小覆盖子串
题目：
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。

示例 1：
	输入：c = 5
	输出：true
	解释：1 * 1 + 2 * 2 = 5

示例 2：
	输入：c = 3
	输出：false

示例 3：
	输入：c = 4
	输出：true

示例 4：
	输入：c = 2
	输出：true

示例 5：
	输入：c = 1
	输出：true

*/

bool judgeSquareSum(int c)
{
	int a = 0;
	int b = sqrt(c);

	while (b >= a)
	{
		//b * b + a * a; 数字可能越界！
		if (b * b > c - a * a)
			b--;
		else if (b * b < c - a * a)
			a++;
		else
			return true;
	}
	return false;
}


int main()
{
	bool test = judgeSquareSum(5);
	bool test0 = judgeSquareSum(1);
	return 0;
}
