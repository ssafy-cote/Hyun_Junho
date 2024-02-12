#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

/*
맵의 크기 1 이상 100 이하의 자연수
0은 벽, 1은 길

캐릭터는 1,1(0,0) 위치
도착점은 n,m위치

캐릭터가 끝자락에 도착한다면 시작지점 포함해서 총 거리를 반환하고
도착하지 못하면 -1을 반환한다.
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

    //n 과 m을 벗어나면 안됨
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