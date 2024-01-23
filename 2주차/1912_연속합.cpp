#include <iostream>
#include <vector>
using namespace std;
//0번째 구간합과 minNum을비교 
//0~1번째 구간합과 1을비교
//0~2번째 구간합과 2를 비교
//0~3번째 구간합과 3을 비교

//-> 0~i번째 구간합과 i를 비교
// 
//[이전 구간합 + i] 보다 [i]가 클 때 구간합은 이전 구간합은 버리고 i부터 시작한다.

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);

	for (int i= 0; i<n; i++)
		cin >> vec[i];

	int maxNum = -2147483648; //최대 구간합
	int curMax = 0; //현재 구간까지 합

	for (int i = 0; i < n; i++)
	{		
		curMax = max(curMax + vec[i], vec[i]);
		maxNum = max(maxNum, curMax);
	}
	cout << maxNum;
}