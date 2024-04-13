#include <iostream>
#include <queue>
#include <deque>
#include <utility>
#define APPLE 2;

using namespace std;

/*
뱀
뱀의 초기 길이는 1이고 방향의 처음은 오른쪽이다.

#규칙
	- 뱀은 이동할 때 머리를 다음 칸으로 이동시킨다.
	- 벽이나 자신의 몸에 부딫히면 게임이 끝난다.
	- 사과가 있다면 꼬리는 움직이지 않은다. (한 칸 늘어난다.)

	# 맨 처음 좌측 상단에는 뱀이 주어지고 이곳에는 사과가 없다.

	15 D,는 15초 뒤에 오른쪽으로 90도 이동한다는 뜻

*/

int board[101][101];
queue<pair<int, char>> q;
int N;
int answer = 0;

class Snake
{
public:
	Snake()
	{
		snake.push_back({ 0, 0 });
		dir = { 0, 1 };
	};
	~Snake() {};

	deque<pair<int, int>> snake;
	pair<int, int> dir;

	pair<int, int> GetHead()
	{
		return snake.front();
	}

	pair<int, int> GetTail()
	{
		return snake.back();
	}

	bool CheckCollision(int x, int y)
	{
		for (pair<int, int> p : snake)
			if (p.first == x && p.second == y)
				return true;

		return false;
	}

	void Move(bool isApple)
	{
		int x = snake.front().first + dir.first;
		int y = snake.front().second + dir.second;
		snake.push_front({ x, y });

		if (!isApple)
			snake.pop_back();
	}

	void ChangeDir(char rot)
	{
		int x = dir.first;
		int y = dir.second;

		if (x == -1 && y == 0) //상
			rot == 'L' ? dir = { 0, -1 } : dir = { 0, 1 };
		else if (x == 1 && y == 0) //하
			rot == 'L' ? dir = { 0, 1 } : dir = { 0, -1 };  //왼쪽 , 오른쪽
		else if (x == 0 && y == -1) //좌
			rot == 'L' ? dir = { 1, 0 } : dir = { -1, 0 };
		else if (x == 0 && y == 1) //우
			rot == 'L' ? dir = { -1, 0 } : dir = { 1, 0 };
	}
};

bool isWall(int x, int y)
{
	return x < 0 || x >= N || y < 0 || y >= N;
}

int GameStart()
{
	Snake* s = new Snake();

	while (true)
	{
		//####DEBUG
		//cout << answer << "초" << '\n';
		//char cboard[101][101] = {};
		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		cboard[i][j] = (board[i][j] == 0 ? 'X' : 'O');
		//	}
		//}

		//for (auto p : s->snake)
		//	cboard[p.first][p.second] = 'S';

		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//		cout << cboard[i][j];

		//	cout << '\n';
		//}
		//cout << '\n';

		//######

		//초 증가
		answer++;

		int x = s->GetHead().first + s->dir.first;
		int y = s->GetHead().second + s->dir.second;

		if (isWall(x, y))
			break;
		if (s->CheckCollision(x, y))
			break;

		//사과 먹은지 여부
		bool isApple = board[x][y] == 2;
		if (isApple)
			board[x][y] = 0;
		s->Move(isApple);

		if (!q.empty())
		{
			int moveTime = q.front().first;

			//해당 시간이 되면 방향을 전환한다.
			if (answer == moveTime)
			{
				s->ChangeDir(q.front().second);
				q.pop();
			}
		}
	}

	delete(s);
	return answer;
}

int main()
{
	int K, L;
	cin >> N >> K;
	while (K--)
	{
		int posX, posY;
		cin >> posX >> posY;

		//문제는 1,1이 시작으로 줬지만
		//0,0배열기준으로 작성했기에 1 빼주기
		board[posX - 1][posY - 1] = APPLE;
	}

	cin >> L;
	while (L--)
	{
		int time;
		char rot;

		cin >> time >> rot;
		q.push({ time, rot });
	}
	cout << GameStart();
}