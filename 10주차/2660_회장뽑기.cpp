#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int adjMatrix[51][51];
int N;
int minimal;
int bfs(int node)
{
	vector<bool> visited(N + 1);
	queue<int> q;
	q.push(node);
	visited[node] = true;
	int depth = -1;

	while (!q.empty())
	{
		int size = q.size();
		depth++;
		while (size--)
		{
			int curNode = q.front();
			q.pop();

			for (int i = 1; i <= N; i++)
			{
				if (!adjMatrix[curNode][i])
					continue;

				if (visited[i])
					continue;

				visited[i] = true;
				q.push(i);
				//cout << curNode << "이 " << i << "와 만남\n";
			}
		}
	}
	minimal = min(minimal, depth);
	return depth;
}

int main()
{
	cin >> N;

	vector<int> v(N + 1);
	minimal = 2147483647;

	int fr = 0;
	int to = 0;

	while (1)
	{
		cin >> fr >> to;
		if (fr == -1 && to == -1)
			break;

		adjMatrix[fr][to] = 1;
		adjMatrix[to][fr] = 1;
	}

	//회장 후보의 점수, 후보의 수
	//회장 후보들

	for (int i = 1; i <= N; i++)
		v[i] = bfs(i);

	vector<int> ceoVec;

	for (int i = 1; i < v.size(); i++)
		if (v[i] == minimal)
			ceoVec.push_back(i);

	cout << minimal << ' ' << ceoVec.size() << '\n';

	for (int i : ceoVec)
		cout << i << ' ';
}