#include <iostream>
#include <deque>
#include <utility>
#include <queue>
#include <functional>
using namespace std;
/*
������ ���� N
�� ��°�� �μ�Ǿ����� �ñ��� ����

�켱���� ť ������������ ���

N�� �־����� M���� �� �߿��� i ��° �ε����� �� ��°�� �������� ����ϱ�

*/
int main()
{
	//�� ��°�� �μ�Ǿ����� �ñ��� ������ ���� ť�� �� ��°�� �����ִ���	
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
			//����, �߿䵵�� ������
			pair<int, int> num = dq.front();

			//�߿䵵�� ������ �ε����� ����.
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