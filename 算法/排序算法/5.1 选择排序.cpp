#include <iostream>
#include <vector>

using namespace std;

/*
* ˼·��
* ÿ�δӴ�������ѡ����С������󣩵�Ԫ�أ��ŵ���ʼλ�ã�
* һ�ΰ�����ѭ����ֱ����Ԫ�طŵ�ĩβ����ʱ��������״̬��
*/

//ʱ�临�Ӷ� O(n^2)
void SelectSort(vector<int>& nums, int n)
{
	for (int i = 0;i <n - 1; ++i)  //n-1��ֹjԽ��
	{
		int min = i;
		//�ҵ�Ԫ����С��λ��
		for (int j = i+1;j<n;++j)
		{
			if (nums[min] > nums[j])
				min = j;
		}
		//����С��Ԫ�ط���ǰ��
		if (min != i)
			std::swap(nums[min], nums[i]);
	}
}


int main()
{
	vector<int> vec{ 1,5,3,6,4,2 };
	SelectSort(vec, vec.size());
	return 0;
}