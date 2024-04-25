#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> vec;
int answerA = 0;
int answerB = 0;
int minAbs = 2147483647;

/*
1. �迭 �Է¹ޱ�
2. start, end�� ���ڷ� ���� �������� �����迭
	* start >= end���Ǹ� �ݺ��� Ż��
	2-1. �� ����� Ư������ ���Ѵ�. sum = vec[start] + vec[end]
		2-1-1. Ư������ ���밪���� 0�� ����� ���� ���Ѵ�.
		2-1-2. Ư������ minAbs���� �۾����ٸ� �� ���� ������ ���Դٴ� ���̹Ƿ� �������ش�.
			2-1-2-1. 0�̳��´ٸ� �������� �ĵ� �ǹǷ� �ݺ����� �������´�.

	��
	2-2
		Ư������ ������ ������ ������ ���̱� ���� start�� ������Ų��.
		Ư������ ����� ������ ����� ���̱� ���� end�� ���ҽ�Ų��.
*/

void twoPointer(int start, int end)
{
	while (start < end)
	{
		int sum = vec[start] + vec[end];

		if (abs(sum) < minAbs)
		{
			minAbs = abs(sum);
			answerA = vec[start];
			answerB = vec[end];

			if (!sum)
				break;
		}

		if (sum < 0)
			start++;
		else if (sum > 0)
			end--;
	}
}

int main()
{
	cin >> N;
	
	vec.resize(N);

	for (int i = 0; i < N; i++)
		cin >> vec[i];
	
	twoPointer(0, N - 1);
	cout << answerA << " " << answerB;
}