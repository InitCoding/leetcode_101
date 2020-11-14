#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��������
//435. Non-overlapping Intervals (Medium)
/*
��Ŀ������
	����������䣬��������Щ���以���ص�����Ҫ�Ƴ���������ٸ�������ֹ���������ص���

�������������
	������һ�����飬�����ɶ�����ȹ̶�Ϊ 2 ��������ɣ���ʾ����Ŀ�ʼ�ͽ�β�����һ��
��������ʾ��Ҫ�Ƴ�������������

Input : [[1, 2], [2, 4], [1, 3]]
Output : 1

����������У����ǿ����Ƴ�����[1, 3]��ʹ��ʣ������� [[1, 2], [2, 4]] �����ص���
*/


//�Ƚ���
bool comparator(const vector<int>& a, const vector<int>& b)
{
	if (a.size() < 2 || b.size() < 2)
		return (a[0] < b[0]);
	
	return (a[1] < b[1]);
}


//ʱ�临�Ӷȣ�O(n)
int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
	//�ȴ����������
	if (intervals.size() < 2)
		return 0;

	//���򷽱�Աȴ�С(�Կռ��β��Ϊ�Ա�ֵ)
	//std::sort(intervals.begin(), intervals.end(), comparator);//�Ƚ���
	
	std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
		{
			if (a.size() < 2 || b.size() < 2)
				return (a[0] < b[0]);
			return (a[1] < b[1]);
		}); //������ʽ

	//���ݱ߽�ֵ���жԱȣ�ȷ���Ƿ��ص�
	int count = 0;
	int lastBoundary = intervals[0][1];   //��ʼֵΪ�߽����
	for (int i = 0; i < intervals.size() - 1; ++i)	//ע���ס�߽����� i��ȡֵ��Χ
	{
		if (lastBoundary > intervals[i + 1][0])  //�ص���������һ���ռ��ĩβ������һ���ռ�ĳ�ʼֵ
			++count;
		else
			lastBoundary = intervals[i+1][1];	//��������������±߽�
	}

	return count;
}

