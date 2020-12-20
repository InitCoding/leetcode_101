#include<iostream>
#include <vector>
#include <stack>

using namespace std;

/*leetcode
* 695. �����������
* https://leetcode-cn.com/problems/max-area-of-island/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
��Ŀ������
	����һ����ά�� 0-1 �������� 0 ��ʾ���� 1 ��ʾ½�ء������Ļ����ڵ�½�ؿ����γɵ�
�죬ÿ������ֻ�������������ĸ��������ڡ������ĵ��������

�����������
������һ����ά���飬�����һ����������ʾ���ĵ��������
Input:
[[1,0,1,1,0,1,0,1],
[1,0,1,1,0,1,1,1],
[0,0,0,0,0,0,0,1]]
Output: 6
���ĵ������Ϊ 6��λ�����Ҳࡣ

*/

/*
* ����˼·��
*		��������ÿ���ڵ�
		->�ҵ�����1�Ľڵ㣬�ֱ�������ڵ���������ҽ��б���������֮����Ҫ ����Ϊ0����ֹ�ظ����㣩
		->ÿ�ҵ�һ��Ϊ1�Ľڵ㣬����Ҫ�����������ң�����ջ��ݹ�ķ�ʽ������
		->�ҵ��������
*/

vector<int> direction{ -1,0,1,0,-1 };

int maxAreaOfIsland(vector<vector<int>>& grid)
{
	int m = grid.size();  //���ٸ����飬����
	int n = m==0 ? 0 : grid[0].size();  //�������������size������
	int local_area = 0;
	int area = 0;
	int x = 0, y = 0;
	for (int i = 0; i <m;++i)
	{
		for (int j =0;j<n;++j)
		{
			if (grid[i][j] == 1)  
			{
				local_area = 1;
				grid[i][j] = 0;  //���㣬��ֹ����ظ�
				stack<pair<int, int>> island;
				island.push({i, j});  //����¼1��λ��
				while (!island.empty())
				{
					int ii = island.top().first;
					int jj = island.top().second;
					island.pop();
					for (int k = 0; k < 4;++k)  //�жϽڵ����������(˳ʱ�뷽����->��->��->��)
					{
						x = ii + direction[k];
						y = jj + direction[k + 1];
						if (x >= 0 && x < m
							&& y >= 0 && y < n && grid[x][y] == 1)
						{
							grid[x][y] = 0;	//���㣬��ֹ����ظ�
							++local_area;
							island.push({ x,y });
						}
					}
				}
				area = max(area, local_area);   //ȡ������

			}
		}
	}

	return area;
}

int main()
{
	vector<vector<int>> grid = { 
				 {1, 1, 0, 0, 0},
				 {1, 1, 0, 0, 0},
				 {0, 0, 0, 1, 1},
				 {0, 0, 0, 1, 1} };
	int ret = maxAreaOfIsland(grid);
	return 0;
}