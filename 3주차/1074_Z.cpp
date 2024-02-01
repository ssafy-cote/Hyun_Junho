#include <iostream>

using namespace std;

int Z(int N, int r, int c)
{
	if (N == 0)
		return 0;

	//���� N�� 4�϶�
	//8x8 ������� 4*4 ������� ����.
	// 4����� ������ ã�ƺ��ű� ����


	//�� ȹ�� ����
	int sqrtN = 1 << (N - 1);
	//��Ʈ����	1 << 3  = 8 
//			0001 -> 1000;

	//��, ���� ��� 4���� ���� ��							-> 1��и� 1~15
	//���� 4���� �۰� ���� �ְ� ���� 4���� ũ�ų� ���� ��	-> 2��и� 16~31
	//���� 4���� ũ�ų� ���� ���� 4���� ���� ��			-> 3��и� 32~47
	//���� 4���� ũ�ų� ���� ���� 4���� ũ�ų� ���� ��		-> 4��и� 48~63

	//�� ��и��� ���� ������ ���� ���� ���� ���� �����ش�.
	if (r < sqrtN && c < sqrtN)					
		return Z(N - 1, r, c);
	else if (r < sqrtN && c >= sqrtN)			
		return (sqrtN * sqrtN) + Z(N - 1, r, c - sqrtN);
	else if (r >= sqrtN && c < sqrtN)
		return (sqrtN * sqrtN * 2) + Z(N - 1, r - sqrtN, c);
	else if (r >= sqrtN && c >= sqrtN)
		return (sqrtN * sqrtN * 3) + Z(N - 1, r - sqrtN, c - sqrtN);
}

int main()
{
	int N, r, c;
	cin >> N >> r >> c;

	cout << Z(N, r, c);
}