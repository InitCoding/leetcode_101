#include<iostream>
#include <vector>

using namespace std;

//��������
/*
˼·��
	���ε�˼�룬�ֿ�����
	��ĳ��������Ϊkey,�Ѵ���key��С��key�ķֳ����ߣ�����key���ұߣ�С��key����ߣ�
	�������߷ֱ���Ϊ������������֣�ֱ������ֻ��һ��ֵ����ʱ��������ģ�
*/



//��������
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


int main()
{
	vector<int> vec{ 5,3,1,6,4,2};
	quickSort(vec, 0, vec.size() - 1);
	return 0;
}