#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

/*
스코빌 배열 2 ~ 100만 원소는 0~100만
스코빌 최소 크기 K 0~10억

스코빌 K가 될 수 없으면 -1 리턴

pq 오름차순 정렬

프로세스
1. 벡터의 값을 pq에 옮긴다.

큐가 비면 반복문 탈출
큐의 top이 k보다 크거나 같으면 탈출

2. num1에 pq의 값을 하나 뽑아온다.
3. num2에 pq의 값을 하나 뽑아온다.
4. 두 값으로 스코빌 지수를 구한다.
5.만들어진 값을 다시 pq에 넣는다.


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