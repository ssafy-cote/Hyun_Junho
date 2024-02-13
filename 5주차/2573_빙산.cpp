#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;
/*

2���� �迭�� �־����� �ų� �ٴ�(���鿡) ������ Ÿ���� ���꿡 ��´�.

�� �ذ� ���� ��, ������ �����ϰ� 
����� ���� üũ�Ѵ�. 
����� 2�� �̻����� �������ٸ� �⵵�� ����Ѵ�.

- N�� M�� 3 �̻� 300�����̴�.
- ������ 1���� 10000�������̴�.
- �迭�� �׵θ��� �׻� 0���� ä������.

-1. 2�� ������ ����  ����ִ� ���ϸ��� üũ�Ѵ�.
- 2. 4������ Ž���Ͽ� �ֺ��� �ٴٰ� �ִ��� Ȯ���ϰ� ���ϸ� ���δ�.

-3.  �⵵�� ������Ų��.

-4. 2�������� ���� ������ bfs�� �����Ѵ�.
- ������ ������ 1�̸� 1�� ���ư���.
   �ƴ� �� �⵵�� �����Ѵ�.

*/
const pair<int, int> dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int field[300][300];
int isVisited[300][300];
int N, M;

void BFS(int i, int j)
{
	queue<pair<int, int>> q;

	q.push({ i, j }); //Ž���� ������ ù ��ǥ�� �����Ѵ�.
	isVisited[i][j] = true;

	//BFS�� ���� �ֺ� ������ Ȯ���Ѵ�.
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
	
	//�Է�
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> field[i][j];
		
	int year = 0;
	int iceParts = 0;
	//ó������ �Է¹��� ������ üũ�Ѵ�.
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (field[i][j] > 0 && !isVisited[i][j])
			{
				iceParts++;

				//������ 1������ �ƴ϶�� �̹� ������ �����Ƿ� 0�� ��ȯ�Ѵ�.
				if (iceParts > 1)
				{
					cout << 0;
					return 0;
				}
				BFS(i, j);
			}
		}
	}
	//0�⵵ ����üũ�� ����� �迭 �ٽ� �ʱ�ȭ
	memset(isVisited, 0, sizeof(isVisited));
	iceParts = 0;
	queue<pair<int, int>> q;

	while (true)
	{
		year++;

		//�׵θ��� Ȯ������ �ʾƵ� �ǹǷ� 1���� N-1������ Ž��, 
		//���� ����üũ�� �ʿ����.
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < M - 1; j++)
			{
				if (field[i][j] > 0)
				{
					//���Ž�� ����
					for (auto curDir : dir)
					{
						//�ֺ��� �ٴ�(0)�̸� ���� ���� ����, 
						//�ٷ� �پ��� ����� ���̹Ƿ� ť�� ��Ƶξ��ٰ� �Ѳ����� ����Ѵ�.
						if (!field[i + curDir.first][j + curDir.second])
							q.push({ i, j });
					}
				}
			}				
		}

		//ť�� ���� ��ǥ�� ��� 1�� ���ָ� ����ش�.
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			field[x][y]--;

			if (field[x][y] < 0)
				field[x][y] = 0;
		}

		//���� ������ ���̺��� ���� ������ ���������� üũ�Ѵ�.
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

		//�������� �⵵ ���, �� 
		//��� �������� 0, 
		//1����̸� ���̺��� �ʱ�ȭ�ϰ� while�� ��ݺ��Ѵ�.
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