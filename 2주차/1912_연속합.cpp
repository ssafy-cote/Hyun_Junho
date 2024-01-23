#include <iostream>
#include <vector>
using namespace std;
//0��° �����հ� minNum���� 
//0~1��° �����հ� 1����
//0~2��° �����հ� 2�� ��
//0~3��° �����հ� 3�� ��

//-> 0~i��° �����հ� i�� ��
// 
//[���� ������ + i] ���� [i]�� Ŭ �� �������� ���� �������� ������ i���� �����Ѵ�.

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);

	for (int i= 0; i<n; i++)
		cin >> vec[i];

	int maxNum = -2147483648; //�ִ� ������
	int curMax = 0; //���� �������� ��

	for (int i = 0; i < n; i++)
	{		
		curMax = max(curMax + vec[i], vec[i]);
		maxNum = max(maxNum, curMax);
	}
	cout << maxNum;
}