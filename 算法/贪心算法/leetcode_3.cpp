#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


//LeetCode 605. 种花问题
/*
* 题目：
假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。
能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。
*/

/*
示例 1:
输入: flowerbed = [1,0,0,0,1], n = 1
输出: True

示例 2:
输入: flowerbed = [1,0,0,0,1], n = 2
输出: False

注意:
	数组内已种好的花不会违反种植规则。
	输入的数组长度范围为 [1, 20000]。
	n 是非负整数，且不会超过输入数组的大小。
*/


//分析：要想插入数据，那么必须得出现连续三个0；
//	特殊情况：数组长读小于2时，数组必须全部为0才可以

bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
	int size = flowerbed.size();

	//特殊情况1
	if (size > 0 && !n)
		return true;

	//特殊情况2
	if (size < 1 || n > size)
		return false;

	for (int i = 0 ; i< size; ++i)
	{
		if(!!flowerbed[i])
			continue;

		//连续三个0才能插入一个
		if (!flowerbed[i]
			&& !flowerbed[max(0,i-1)]  //保证首位为0且不越界
			&& !flowerbed[min(i+1,size-1)]) ////保证末尾为0且不越界
		{
			flowerbed[i] = 1;
			--n;
		}
	}
	
	return n <= 0;
}
