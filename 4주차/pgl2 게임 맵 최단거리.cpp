#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

/*
���� ũ�� 1 �̻� 100 ������ �ڿ���
0�� ��, 1�� ��

ĳ���ʹ� 1,1(0,0) ��ġ
�������� n,m��ġ

ĳ���Ͱ� ���ڶ��� �����Ѵٸ� �������� �����ؼ� �� �Ÿ��� ��ȯ�ϰ�
�������� ���ϸ� -1�� ��ȯ�Ѵ�.
*/

pair<int, int> start = {0,0};
pair<int, int> endPos;
int isVisited[100][100];


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();

    endPos = { n - 1, m - 1 };

    //n �� m�� ����� �ȵ�
    if (endPos.first < 0 || endPos.first >= n || endPos.second < 0 || endPos.second >= m)
        return -1;

    queue<pair<int, int>> q;

    q.push({ start.first, start.second });
    isVisited[start.first][start.second] += 1;

    const pair<int, int> dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    while (!q.empty())
    {
        pair<int, int> curPos = { q.front().first, q.front().second };
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = curPos.first + dir[i].first;
            int y = curPos.second + dir[i].second;

            if (x >= 0 && x < n && y >= 0 && y < m)
            {
                if (maps[x][y] == 1 && !isVisited[x][y])
                {
                    isVisited[x][y] = isVisited[curPos.first][curPos.second] + 1;
                    q.push({ x, y });
                }
            }
        }
    }

    if (!isVisited[n - 1][m - 1])
        return -1;

    return isVisited[n-1][m-1];
}

int main()
{
    //vector<vector<int>> v = { {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1} };
    vector<vector<int>> v = { {1,0,1,1,1} };
    cout << solution(v);
}