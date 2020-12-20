#include<iostream>
#include <vector>
#include <stack>

using namespace std;

/*leetcode
* 695. 岛屿的最大面积
* https://leetcode-cn.com/problems/max-area-of-island/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
题目描述：
	给定一个二维的 0-1 矩阵，其中 0 表示海洋， 1 表示陆地。单独的或相邻的陆地可以形成岛
屿，每个格子只与其上下左右四个格子相邻。求最大的岛屿面积。

输入输出样例
输入是一个二维数组，输出是一个整数，表示最大的岛屿面积。
Input:
[[1,0,1,1,0,1,0,1],
[1,0,1,1,0,1,1,1],
[0,0,0,0,0,0,0,1]]
Output: 6
最大的岛屿面积为 6，位于最右侧。

*/

/*
* 解题思路：
*		遍历数组每个节点
		->找到等于1的节点，分别在这个节点的上下左右进行遍历（遍历之后需要 设置为0，防止重复计算）
		->每找到一个为1的节点，都需要遍历上下左右（利用栈或递归的方式来做）
		->找到最大的面积
*/

vector<int> direction{ -1,0,1,0,-1 };

int maxAreaOfIsland(vector<vector<int>>& grid)
{
	int m = grid.size();  //多少个数组，行数
	int n = m==0 ? 0 : grid[0].size();  //单个数组包含的size，列数
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
				grid[i][j] = 0;  //置零，防止检测重复
				stack<pair<int, int>> island;
				island.push({i, j});  //仅记录1的位置
				while (!island.empty())
				{
					int ii = island.top().first;
					int jj = island.top().second;
					island.pop();
					for (int k = 0; k < 4;++k)  //判断节点的上下左右(顺时针方向：上->右->下->左)
					{
						x = ii + direction[k];
						y = jj + direction[k + 1];
						if (x >= 0 && x < m
							&& y >= 0 && y < n && grid[x][y] == 1)
						{
							grid[x][y] = 0;	//置零，防止检测重复
							++local_area;
							island.push({ x,y });
						}
					}
				}
				area = max(area, local_area);   //取最大面积

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