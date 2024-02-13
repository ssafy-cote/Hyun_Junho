#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;
/*

2차원 배열이 주어지고 매년 바다(공백에) 인접한 타일은 빙산에 녹는다.

매 해가 지날 때, 빙산을 갱신하고 
덩어리의 수를 체크한다. 
덩어리가 2개 이상으로 갈라진다면 년도를 출력한다.

- N과 M은 3 이상 300이하이다.
- 빙산은 1부터 10000개까지이다.
- 배열의 테두리는 항상 0으로 채워진다.

-1. 2중 포문을 돌며  들어있는 빙하마다 체크한다.
- 2. 4방향을 탐색하여 주변에 바다가 있는지 확인하고 빙하를 녹인다.

-3.  년도를 증가시킨다.

-4. 2중포문을 돌며 빙산의 bfs를 수행한다.
- 빙산의 개수가 1이면 1로 돌아간다.
   아닐 시 년도를 증가한다.

*/
const pair<int, int> dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int field[300][300];
int isVisited[300][300];
int N, M;

void BFS(int i, int j)
{
	queue<pair<int, int>> q;

	q.push({ i, j }); //탐색을 수행할 첫 좌표를 삽입한다.
	isVisited[i][j] = true;

	//BFS를 돌며 주변 빙산을 확인한다.
	while (!q.empty())
	{
		pair<int, int> curPos = q.front();
		q.pop();

		for (auto curDir : dir)
		{
			int x = curPos.first + curDir.first;
			int y = curPos.second + curDir.second;

			if (field[x][y] > 0 && !isVisited[x][y] )
			{
				q.push({ x, y });
				isVisited[x][y] = true;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	
	//입력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> field[i][j];
		
	int year = 0;
	int iceParts = 0;
	//처음으로 입력받은 빙산을 체크한다.
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (field[i][j] > 0 && !isVisited[i][j])
			{
				iceParts++;

				//빙산이 1조각이 아니라면 이미 갈라져 있으므로 0을 반환한다.
				if (iceParts > 1)
				{
					cout << 0;
					return 0;
				}
				BFS(i, j);
			}
		}
	}
	//0년도 빙산체크에 사용한 배열 다시 초기화
	memset(isVisited, 0, sizeof(isVisited));
	iceParts = 0;
	queue<pair<int, int>> q;

	while (true)
	{
		year++;

		//테두리는 확인하지 않아도 되므로 1부터 N-1까지만 탐색, 
		//따라서 범위체크도 필요없다.
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < M - 1; j++)
			{
				if (field[i][j] > 0)
				{
					//사방탐색 수행
					for (auto curDir : dir)
					{
						//주변이 바다(0)이면 빙산 갯수 감소, 
						//바로 줄어들면 계산이 꼬이므로 큐에 담아두었다가 한꺼번에 계산한다.
						if (!field[i + curDir.first][j + curDir.second])
							q.push({ i, j });
					}
				}
			}				
		}

		//큐에 쌓인 좌표를 모두 1씩 빼주며 비워준다.
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			field[x][y]--;

			if (field[x][y] < 0)
				field[x][y] = 0;
		}

		//녹은 빙산의 테이블을 보고 빙산이 갈라졌는지 체크한다.
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < M - 1; j++)
			{
				if (field[i][j] > 0 && !isVisited[i][j])
				{
					iceParts++;
					BFS(i, j);
				}
			}
		}

		//갈라지면 년도 출력, 다 
		//녹아 없어지면 0, 
		//1덩어리이면 테이블을 초기화하고 while을 재반복한다.
		if (iceParts > 1)
		{
			cout << year;
			break;
		}
		else if (iceParts == 0)
		{
			cout << 0;
			break;
		}
		else
		{
			memset(isVisited, 0, sizeof(isVisited));
			iceParts = 0;
		}
	}
}