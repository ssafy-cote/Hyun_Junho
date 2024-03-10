#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;
/*
	귤 고르기
	수확한 귤 중 k개를 골라 상자에 담아 판매한다.

	배열의 귤을 해시로 바꾼다.
	해시의 value 값으로 정렬한다.
*/

bool Comp(pair<int, int>& a, pair<int, int>& b)
{
	//귤 갯수가 많은 순으로 내림차순 정렬
	return b.second < a.second; // left가 크면 오른쪽으로 넘긴다.
}

int solution(int k, vector<int> tangerine) {
	int answer = 0;

	unordered_map<int, int> map;
	for (int i : tangerine)
	{		
		//찾았는지 여부를 상수로 살피면 count 함수
		//찾으면 1, 못찾으면 0
		// int isFind = map.count(i);
		
		//find할 때 값을 못찾으면 iter end를 반환
		auto iter = map.find(i);
		auto iterEnd = map.end();

		if (iter != iterEnd)			
			(*iter).second++;			
		else
			map.insert(make_pair(i, 1));
	}

	int a = 0;
	vector<pair<int, int>> copyMap(map.begin(), map.end());
	sort(copyMap.begin(), copyMap.end(), Comp);

	int sum = k;
	for (auto i : copyMap)
	{
		answer++;
		k -= i.second;
		if (k <= 0)
			break;
	}

	return answer;
}

int main()
{
	vector<int> vec = { 1,1,1,1,2,2,2,3 };
	//1(1), 2(2), 3(2), 4(1), 5(2)

	cout << solution(2, vec);


}