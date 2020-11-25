#include <iostream>
#include <vector>

using namespace std;

//����ѡ��

//leetcode
//215. �����еĵ�K�����Ԫ��
/*
* ��һ��δ����������У��ҵ��� k �������
*/

/*
* ˼·��
*	���ÿ��������˼�룬����ֻ��Ҫ�ҵ�ǰ���kλ�Ϳ���
*/

int PartSelection(vector<int>& nums, int left, int right)
{
	int start = left;
	int end = right;
	int key = nums[right];
	while (start<end)
	{
		while (start<end && nums[start] <= key)
			++start;
		while (start<end && nums[end] >= key)
			--end;
		std::swap(nums[start], nums[end]);
	}
	std::swap(nums[right], nums[end]);
	return end;
}

int findKthLargest(vector<int>& nums, int k)
{
	int left = 0;
	int right = nums.size() - 1;
	int target = nums.size() - k;  //��k��Ԫ�ص��±�
	while (left <right)
	{
		//ÿ���ҵ����ֵ��м�λ�ã����бȽ�
		int mid = PartSelection(nums, left, right);
		if (mid == target)
		{
			return nums[mid];
		}
		else if (mid < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return nums[left];
}





int main()
{
	vector<int> vec{ 3,2,1,6,5,0 };
	int number = findKthLargest(vec, 3);
	return 0;
}