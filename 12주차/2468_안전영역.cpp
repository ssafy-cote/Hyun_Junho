#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>

using namespace std;

const pair<int, int> dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N;
int arr[100][100];

int maxNum = 0;
int answer = 0;
void BFS(int x, int y, bool isVisited[100][100])
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	isVisited[x][y] = true;

	while (!q.empty())
	{
		auto curPos = q.front();
		q.pop();
		
		for (auto nxtDir : dir)
		{
			int nxtX = curPos.first + nxtDir.first;
			int nxtY = curPos.second + nxtDir.second;

			if (nxtX < 0 || nxtY < 0 || nxtX >= N || nxtY >= N)
				continue;

			if (isVisited[nxtX][nxtY] || arr[nxtX][nxtY] == -1)
				continue;

			isVisited[nxtX][nxtY] = true;
			q.push({ nxtX, nxtY });
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			maxNum = max(maxNum, arr[i][j]);
		}
			
	}
	
	//ºñ
	for (int i = 0; i <= maxNum; i++)
	{
		bool isVisited[100][100] = {};

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (arr[j][k] == i)
					arr[j][k] = -1; //ºø¹°
			}
		}
		
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (arr[j][k] != -1 && !isVisited[j][k])
				{
					BFS(j, k, isVisited);
					cnt++;
				}
					
			}
		}

		answer = max(answer, cnt);
	}
	cout << answer;	
	
}