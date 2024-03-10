#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;
/*
	�� ����
	��Ȯ�� �� �� k���� ��� ���ڿ� ��� �Ǹ��Ѵ�.

	�迭�� ���� �ؽ÷� �ٲ۴�.
	�ؽ��� value ������ �����Ѵ�.
*/

bool Comp(pair<int, int>& a, pair<int, int>& b)
{
	//�� ������ ���� ������ �������� ����
	return b.second < a.second; // left�� ũ�� ���������� �ѱ��.
}

int solution(int k, vector<int> tangerine) {
	int answer = 0;

	unordered_map<int, int> map;
	for (int i : tangerine)
	{		
		//ã�Ҵ��� ���θ� ����� ���Ǹ� count �Լ�
		//ã���� 1, ��ã���� 0
		// int isFind = map.count(i);
		
		//find�� �� ���� ��ã���� iter end�� ��ȯ
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