#include <iostream>
#include <utility>
#include <queue>
using namespace std;

/*
주사위 결과가 100을 넘어가면 안된다.

이동은 1~ 6사이만 가능하다.

뱀과 사다리는 1과 100에 없다.

BFS 
*/

int arr[101];
//레벨별 bfs 6칸씩?
int N, M;

int bfs()
{
	int isVisited[101] = {};
	queue<int> q;
	q.push(1);
	int cnt = 0;
	while (!q.empty())
	{
		int size = q.size();
		cnt++;
		while (size--)
		{
			int idx = q.front();
			q.pop();

			for (int i = 1; i <= 6; i++)
			{
				int nIdx = idx + i;

				if (nIdx > 100)
					continue;

				if (isVisited[nIdx])
					continue;

				if (arr[nIdx])
					nIdx = arr[nIdx];

				if (nIdx == 100)
					return cnt;

				isVisited[nIdx] = cnt;
				q.push(nIdx);
			}
		}
	}
	return -1;
}

int main()
{
	cin >> N >> M;

	int from, to;
	for (int i = 0; i < N+M; i++)
	{
		cin >> from >> to;
		arr[from] = to;
	}

	cout << bfs();
}