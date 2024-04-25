#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

/*
���ں� �迭 2 ~ 100�� ���Ҵ� 0~100��
���ں� �ּ� ũ�� K 0~10��

���ں� K�� �� �� ������ -1 ����

pq �������� ����

���μ���
1. ������ ���� pq�� �ű��.

ť�� ��� �ݺ��� Ż��
ť�� top�� k���� ũ�ų� ������ Ż��

2. num1�� pq�� ���� �ϳ� �̾ƿ´�.
3. num2�� pq�� ���� �ϳ� �̾ƿ´�.
4. �� ������ ���ں� ������ ���Ѵ�.
5.������� ���� �ٽ� pq�� �ִ´�.


*/

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i : scoville)
		pq.push(i);

	while (!pq.empty())
	{
		int num1 = pq.top();
		if (num1 >= K)
			break;

		pq.pop();

		if (pq.empty())
			return -1;

		int num2 = pq.top();
		pq.pop();

		int scobil = min(num1, num2) + (max(num1, num2) * 2);
		pq.push(scobil);
		answer++;
	}

	return answer;
}

int main()
{
	vector<int> sco = { 1, 2, 3, 9, 10, 12 };
	int k = 7;
	cout << solution(sco, k);
}