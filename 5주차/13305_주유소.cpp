#include <iostream>
#define LL long long

using namespace std;

int cityArr[100001]; //도시 리터당 가격 1리터에 10억원??
int cityDistance[100000]; // 거리 1 ~10억

int main()
{
	//N개의 도시,
	/*
	원 안의 숫자는 그 도시에 있는 주유소의 리터당 가격
	도로 위의 숫자는 도로의 길이
	*/

	/*최소비용은 시작지점의 기름값으로 시작한다.
	* 거리만큼 비용을 증가시키고 다음 목적지로 간다.
	*  이전 목적지보다 가격이 싸면 이 가격을 최소비용으로 삼는다.
	* 거리만큼 비용을 증가시키고 다음 목적지로 간다.
	*/
	int N; //2~100,000
	LL minCost = 0;
	LL totalCost = 0;
	cin >> N;
	//N-1개의 도로의 길이 입력받기
	for (int i = 0; i < N-1; i++)
		cin >> cityDistance[i];

	for (int i = 0; i < N; i++)
		cin >> cityArr[i];

	minCost = cityArr[0];
	totalCost = minCost * cityDistance[0];

	//2번째 행선지부터 시작
	for (int i = 1; i < N; i++)
	{
		//이 행선지의 기름이 더 싸다면
		if (minCost > cityArr[i])
				minCost = cityArr[i];
		
		totalCost += minCost * cityDistance[i];
	}
	cout << totalCost;
}