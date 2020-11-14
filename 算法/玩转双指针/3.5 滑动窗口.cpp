#include <iostream>
#include<map>

using namespace std;

//滑动窗口
//76. Minimum Window Substring (Hard)
/*
* 76. 最小覆盖子串
题目：
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。


示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"

示例 2：
输入：s = "a", t = "a"
输出："a"
 
提示：
	1 <= s.length, t.length <= 105
	s 和 t 由英文字母组成
*/


/*
* 思路：根据滑动窗口的思维，滑动窗口window范围内必须包含所有t的字符（包含的字符数必须大于等于t的所有字符）；
*		首先初始化left，right指向s的第一个元素，滑动窗口的范围初始为s.size;
*		移动right，找到第一个可行的窗口（包含所有t所有字符的窗口）；
*		此时再移动left，缩小窗口范围，每次更新窗口都记录当前窗口的起点和窗口大小，方便之后s.substr调用；
* 
* 注意：如何确定范围并逐步缩小？ 此处是很重要的环节
*	遍历的所有字符，只有出现了t的字符且出现此处与t的一致才能满足当前字符的条件
*	
	对于right, 记录出现字符次数大于等于t的字符数（right是窗口的尾部，可能包含了多于t的字符出现次数）
		伪代码：
			if(字符ch出现在t中)
*			{
*				window[ch]++
*				if(window[ch] == t中ch出现的次数)
*					已匹配的字符matched++；
*			}
*			right++;
*	
	对于left，每次遍历需要将遍历right时，多出来的字符减掉，逐步缩效范围
		伪代码：
		while(matched == chars.size)  //遍历当前窗口，移动left的条件是 已匹配的字符==chars.size()
		{
			if(字符ch出现在t中)
*			{
*				window[ch]--
*				if(window[ch] == t中ch出现的次数)
*					已匹配的字符matched--；
*			}
*			left++;
		}
*/


//  时间复杂度 O(n)
string minWindow(string s, string t)
{
	if (s.size() < t.size())
		return "";

	//记录每个字符出现次数
	std::map<char, int> chars;
	for (char ch : t)
		chars[ch]++;

	int left = 0;
	int right = 0;	
	int matched = 0;  //left-right 范围内已匹配的字符数

	int start = 0;  //窗口起点
	int minLen = s.size() + 1;//窗口大小
	std::map<char, int> window; //窗口范围，记录所有匹配的字符个数
	while (right < s.size())  //遍历s的全部字符
	{
		char ch = s[right];

		//移动right，找到s中包含t的所有字符的范围
		if (chars.count(ch))
		{
			window[ch]++;
			if (window[ch] == chars[ch])  //当匹配的字符个数与t中的一致，则表示该字符已匹配
				matched++;
		}
		right++;

		//left-right这个范围匹配了所有的t的字符, 此时window可能包含了多个t的字符，需要移动left，缩小滑动窗口的范围

		//在保证匹配全部字符的情况下，移动left
		while(matched == chars.size())
		{
			//更新窗口位置
			if (right - left < minLen)
			{
				minLen = right - left; //此处不需要+1, 因为right已经后移了一步
				start = left;
			}

			ch = s[left];
			if (chars.count(ch))
			{
				window[ch]--;
				if (window[ch] < chars[ch])
					matched--;
			}

			left++;
		}
	}

	return  minLen > s.size() ? "" : s.substr(start, minLen);
}

int main()
{
	//string s = "ADOBECODEBANC";
	//string t = "ABC";

	//string min = minWindow(s, t);

	string s = "aa";
	string t = "aa";
	string min = minWindow(s, t);

	return 0;
}
