#include <iostream>

using namespace std;

/*
돌을 한 개 가져갈 때
돌을 두 개 가져갈 때
돌을 세 개 가져갈 때

*/

int main()
{
	int N;
	cin >> N;
	cout << (N % 2 ? "SK" : "CY");
}