#include <iostream>

using namespace std;

/*
1, 00, 11 만 사용하여 DP만들기

dp[1] = 1

dp[2] = 00
dp[2] = 11

dp[3] = 00 1
dp[3] = 1 00
dp[3] = 1 11

dp[4] = 00 00
dp[4] = 00 11
dp[4] = 1 00 1
dp[4] = 1100
dp[4] = 11 11

dp[5] =  00001
dp[5] =  00100
dp[5] =  10000
dp[5] =  00111
dp[5] =  10011
dp[5] =  11001
dp[5] =  11100
dp[5] =  11111

//dp[N] 은 N-1의 수 + N-2의 수의 합이다?
*/

int dp[1000001];

int main()
{
	
	int N, answer;
	cin >> N;

	dp[1] = 1; //0은 00으로 붙어버려서 1 한가지 뿐
	dp[2] = 2; //같은 숫자끼리 붙은것만 사용 가능(00, 11)

	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	
	cout << dp[N];

}