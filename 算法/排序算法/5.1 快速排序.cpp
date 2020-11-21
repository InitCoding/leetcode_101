#include<iostream>
#include <vector>
#include <stack>

using namespace std;

//��������
/*
˼·��
	���ε�˼�룬�ֿ�����
	��ĳ��������Ϊkey,�Ѵ���key��С��key�ķֳ����ߣ�����key���ұߣ�С��key����ߣ�
	�������߷ֱ���Ϊ������������֣�ֱ������ֻ��һ��ֵ����ʱ��������ģ�
*/


//�������򡾵ݹ顿
void quickSort(vector<int>& nums, int left, int right)
{
	if (left + 1 >= right)
		return;

	int first = left;
	int last = right;
	int key = nums[last];  //�˴�ѡ��lastԪ��Ϊkey
	while (first < last)
	{
		while (first<last && nums[first]<=key)
		{
			first++;
		}
		//��ӷ�
		if(first<last)
			nums[last] = nums[first];

		while (first<last && nums[last] >=key)
		{
			last--;
		}
		if(first < last)
			nums[first] = nums[last];
	}
	nums[last] = key;  //��ӷ���Ҫ��key�Ż�ȥ
	quickSort(nums, left, first - 1);   //ע��߽�Ŀ���
	quickSort(nums, first + 1, right);
}


//��������ѭ����
int PartSort(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		int key = nums[right];
		while (left<right)
		{
			while (left<right && nums[left] <= key)
				left++;
			if (left < right)
				nums[right--] = nums[left];

			while (left <right && nums[right] >= key)
				right--;
			if (left < right)
				nums[left++] = nums[right];
		}
		nums[right] = key;
	}
	return right;
}
void quickSort1(vector<int>& nums, int left, int right) 
{
	if (left + 1 < right)
	{
		stack<int> s;
		int boundary = PartSort(nums, left, right);
		if (boundary - 1 > left)
		{
			s.push(left);
			s.push(boundary - 1);
		}
		if (boundary + 1 < right)
		{
			s.push(boundary + 1);
			s.push(right);
		}

		while (!s.empty())
		{
			int end = s.top();
			s.pop();
			int start = s.top();
			s.pop();
			
			boundary = PartSort(nums, start, end);
			if (boundary - 1 > start)
			{
				s.push(start);
				s.push(boundary - 1);
			}
			if (boundary + 1 < end)
			{
				s.push(boundary + 1);
				s.push(end);
			}
		}
	}

}


int main()
{
	vector<int> vec{ 5,3,1,6,4,2};
	quickSort1(vec, 0, vec.size() - 1);
	return 0;
}