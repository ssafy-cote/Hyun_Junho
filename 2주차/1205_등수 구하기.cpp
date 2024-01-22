#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;	// 0 <= N <=P
	int T; //�¼��� ���ο� ����
	int P; //10 <= P < 50 // ��ŷ�� �ö� �� �ִ� ������ ����

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
		if (T < vec[i]) // ��ũ�� ������
			rank++;
		else if (T > vec[i])// ��ũ�� ������
			break;

		count++;		
	}

	if (count >= P)
		rank = -1;

	cout << rank;
}