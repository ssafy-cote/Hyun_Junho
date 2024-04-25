#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<string, int>& v1, pair<string, int>& v2)
{
	/*
	1순위 : 자주 나오는 단어
	2순위 : 단어의 길이
	3순위 : 사전 순
	*/

	if (v1.second == v2.second) //자주나오는 단어의 빈도가 같다면
	{
		if (v1.first.size() == v2.first.size()) //그 단어의 길이도 같다면
			return v1.first < v2.first; //사전순 확인
		else
			return v1.first.size() > v2.first.size();
	}
	return v1.second > v2.second;
}

vector<pair<string, int>> mSort(map<string, int>& maps)
{
	vector<pair<string, int>> vec;

	for (auto i : maps)
		vec.push_back(i);
	
	sort(vec.begin(), vec.end(), compare);
	
	return vec;
}

int main()
{
	int N, M;

	cin >> N >> M;

	map<string, int> maps;

	string s;

	//insert 함수의 반환 타입 iter옆에 들어있는 bool로 들어갔는지 판단한다.
	//pair<iterator, bool> insert(const pair<const Key, Type>& val);
	pair<map<string, int>::iterator, bool> insertReturn;

	while (N--)
	{
		cin >> s;
		//바로 외운 단어
		if (s.size() < M)
			continue;	

		//정상적으로 들어가면 true 반환, 아니면 false 반환
		insertReturn = maps.insert({ s, 0 }); 
		if (!insertReturn.second)
			maps[s]++;
	}
	vector<pair<string, int>> vec = mSort(maps);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i].first << '\n';
}