#include <iostream>
#include <deque>
#include <utility>
#include <queue>
#include <functional>
using namespace std;
/*
문서의 개수 N
몇 번째로 인쇄되었는지 궁금한 문서

우선순위 큐 내림차순으로 담기

N이 주어지면 M개의 수 중에서 i 번째 인덱스는 몇 번째로 나오는지 출력하기

*/
int main()
{
	//몇 번째로 인쇄되었는지 궁금한 문서가 현재 큐에 몇 번째에 놓여있는지	
	int N, M, idx, rank;
	cin >> N;
	
	while (N--)
	{
		priority_queue<int, vector<int>, less<int>> pq;
		deque<pair<int, int>> dq;
		cin >> M >> idx;
		for (int i = 0; i < M; i++)
		{
			cin >> rank;
			pq.push(rank);
			dq.push_back({ i, rank });		
		}

		int cnt = 1;
		while (!dq.empty())
		{
			//순서, 중요도로 세팅함
			pair<int, int> num = dq.front();

			//중요도가 같으면 인덱스를 본다.
			if (pq.top() == num.second)
			{				
				if (num.first == idx)
				{
					cout << cnt << '\n';
					break;
				}					
				pq.pop();				
				dq.pop_front();
				cnt++;
			}
			else
			{
				dq.push_back(dq.front());
				dq.pop_front();

			}
		}
	}
	
	


}