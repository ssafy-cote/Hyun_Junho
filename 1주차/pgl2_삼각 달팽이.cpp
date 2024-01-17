#include <iostream>
#include <vector>
#include <utility>

#define y first
#define x second

using namespace std;

int arr[1001][1001] = {};

vector<int> solution(int n) {
    //세로, 가로, 좌상 대각
    const pair<int, int> delta[] = {{1,0},{0,1},{-1,-1}};
    pair<int, int> curPos = {-1,0}; //시작지점

    int N = n+1;
    int cnt = 1; //넣는 숫자
    int moveDir = 0; //방향값
    
    while (N--)
    {
        moveDir %= 3; // 0, 1, 2
        for (int i = 0; i < N; i++)
        {
           curPos.y += delta[moveDir].y;
           curPos.x += delta[moveDir].x;
           arr[curPos.y][curPos.x] = cnt;           
           cnt++;          
        }
        moveDir++;
    }
    //
    vector<int> answer;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i + 1; j++)
            answer.push_back(arr[i][j]);

    return answer;
}

int main()
{
    int n = 5;
    solution(n);
}