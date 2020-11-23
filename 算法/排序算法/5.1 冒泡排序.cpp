#include <iostream>
#include <vector>

using namespace std;

/*
* ˼·��
*	�Ƚ����ڵ�����Ԫ�ش�С������λ��ֱ��û��Ԫ����Ҫ����������������ɡ�
*/

//ʱ�临�Ӷ� O(n^2)
void BubbleSort(vector<int>& nums, int n)
{
	bool flag = false;  //�Ƿ�����
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0;j< n-i-1;++j)  //��jλ�͵�j+1��λ�ñȽ�
		{
			if (nums[j] > nums[j + 1])
			{
				flag = true;
				std::swap(nums[j], nums[j + 1]);
			}
		}
		if(!flag)
			break;
	}
}


int main()
{
	vector<int> vec{ 1,5,3,6,4,2 };
	BubbleSort(vec, vec.size());
	return 0;
}