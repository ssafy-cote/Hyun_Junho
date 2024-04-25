#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

vector<long long> vec;
bool isUsed[10];
int N, M;
int maxSize = 0;
int maxSong = 0;
int answer = 2147483647;

void powerSet(int dep)
{
	if (dep == N)
	{
		long long sum = 0;
		int cnt = 0;
		int bitCheck = 0;
		for (int i = 0; i < N; i++)
		{
			if (isUsed[i])
			{
				sum |= vec[i];
				cnt++;
			}
		}

		for (int i = 0; i < M; i++)
			if (sum & (1LL << i))
				bitCheck++;

		//�ּ� ���� ���ϱ�
		//�׸��� �ִ��� ���� ���̾�ߵ�
		if (bitCheck && (bitCheck >= maxSong))
		{
			maxSong = bitCheck;
			answer = min(answer, cnt);
		}
		return;
	}

	isUsed[dep] = true;
	powerSet(dep + 1);
	isUsed[dep] = false;
	powerSet(dep + 1);
}

int main()
{
	cin >> N >> M;
	vec.resize(N);
	maxSize = (1 << M) - 1;

	string s1, s2;
	for (int i = 0; i < N; i++)
	{
		cin >> s1 >> s2;
		long long sum = 0;

		//i�� �� 0, 1, 2, 3, 4, �̸� -1, -2, -3, -4, -5�� ���´�.
		//cout << N+1+(~i) << '\n';

		for (int j = 0; j < M; j++)
			if (s2[M + (~j)] == 'Y')
				sum += (1LL << j);

		vec[i] = sum;
	}

	//�κ����� ���ϱ�
	powerSet(0);

	cout << (answer == 2147483647 ? -1 : answer);
}