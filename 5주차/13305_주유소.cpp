#include <iostream>
#define LL long long

using namespace std;

int cityArr[100001]; //���� ���ʹ� ���� 1���Ϳ� 10���??
int cityDistance[100000]; // �Ÿ� 1 ~10��

int main()
{
	//N���� ����,
	/*
	�� ���� ���ڴ� �� ���ÿ� �ִ� �������� ���ʹ� ����
	���� ���� ���ڴ� ������ ����
	*/

	/*�ּҺ���� ���������� �⸧������ �����Ѵ�.
	* �Ÿ���ŭ ����� ������Ű�� ���� �������� ����.
	*  ���� ���������� ������ �θ� �� ������ �ּҺ������ ��´�.
	* �Ÿ���ŭ ����� ������Ű�� ���� �������� ����.
	*/
	int N; //2~100,000
	LL minCost = 0;
	LL totalCost = 0;
	cin >> N;
	//N-1���� ������ ���� �Է¹ޱ�
	for (int i = 0; i < N-1; i++)
		cin >> cityDistance[i];

	for (int i = 0; i < N; i++)
		cin >> cityArr[i];

	minCost = cityArr[0];
	totalCost = minCost * cityDistance[0];

	//2��° �༱������ ����
	for (int i = 1; i < N; i++)
	{
		//�� �༱���� �⸧�� �� �δٸ�
		if (minCost > cityArr[i])
				minCost = cityArr[i];
		
		totalCost += minCost * cityDistance[i];
	}
	cout << totalCost;
}