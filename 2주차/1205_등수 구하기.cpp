#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;	// 0 <= N <=P
	int T; //태수의 새로운 점수
	int P; //10 <= P < 50 // 랭킹에 올라갈 수 있는 점수의 개수

	cin >> N >> T >> P;
	vector<int> vec(N);

	for(int i = 0; i< N; i++)
		cin >> vec[i];

	int rank = 1;
	int count = 0;

	if (N == 0)
	{
		cout << rank;
		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		if (T < vec[i]) // 랭크가 낮으면
			rank++;
		else if (T > vec[i])// 랭크가 높으면
			break;

		count++;		
	}

	if (count >= P)
		rank = -1;

	cout << rank;
}