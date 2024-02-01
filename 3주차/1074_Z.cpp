#include <iostream>

using namespace std;

int Z(int N, int r, int c)
{
	if (N == 0)
		return 0;

	//만약 N이 4일때
	//8x8 사이즈면 4*4 사이즈로 본다.
	// 4등분을 나눠서 찾아볼거기 때문


	//한 획의 길이
	int sqrtN = 1 << (N - 1);
	//비트연산	1 << 3  = 8 
//			0001 -> 1000;

	//행, 열이 모두 4보다 작을 때							-> 1사분면 1~15
	//행은 4보다 작고 내에 있고 열이 4보다 크거나 같을 때	-> 2사분면 16~31
	//행이 4보다 크거나 같고 열이 4보다 작을 때			-> 3사분면 32~47
	//행이 4보다 크거나 같고 열이 4보다 크거나 같을 때		-> 4사분면 48~63

	//각 사분면이 끝날 때마다 이전 끝난 면의 값을 더해준다.
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