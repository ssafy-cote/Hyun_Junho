#include <iostream>

using namespace std;

int main()
{
	int dp[12] = {};
	dp[1] = 1; // 1
	dp[2] = 2; // 1+1, 2
	dp[3] = 4; //1+1+1, 1+2, 2+1, 3
	
	for(int i = 4; i<12; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	int n, m;
	cin >> n;
	while (n--)
	{
		cin >> m;
		cout << dp[m] << '\n';
	}
}