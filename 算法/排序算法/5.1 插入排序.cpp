#include<iostream>
#include <vector>

using namespace std;

/*
* ˼·���������i������ʱ��ǰi-1�������Ѿ�����
* ��ʱֻ�轫��i����ǰ��i-1����бȽϣ��ҵ������λ�ã�
* �ƶ���λ�ú����Ԫ�أ��������ݲ��뵽��λ�ü���
* 
* ���ģ���λ��-->��λ-->��������
*/

 //ʱ�临�Ӷ�O(n^2)
void InsertSort(vector<int>& nums, int n)
{
	for (int i = 1;i <n;++i)  //i��1��ʼ
	{
		//�ҵ�λ�ò�������λ
		int key = nums[i];
		int j = i - 1;
		for (;j >=0 && key<nums[j];--j)
		{
			nums[j + 1] = nums[j];
		}

		//��������
		nums[j + 1] = key;
	}
}


int main()
{
	vector<int> vec{ 5,3,4,2,1 };
	InsertSort(vec, vec.size());
	return 0;
}