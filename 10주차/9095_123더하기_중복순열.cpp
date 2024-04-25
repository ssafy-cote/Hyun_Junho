#include <iostream>
#include <vector>
using namespace std;

const int input[] = { 1, 2, 3 };
vector<int> vec;
int N;
int answer = 0;
void duplePerm()
{
	int sum = 0;
	for (int i = 0; i < vec.size(); i++)
		sum += vec[i];
	
	if (sum >= N)
	{
		if (sum == N)
			answer++;

		return;
	}

	for (int i = 0; i < 3; i++)
	{
		vec.push_back(input[i]);
		duplePerm();
		vec.pop_back();
	}
}

int main()
{
	int tc = 0;
	cin >> tc;
	
	while (tc--)
	{
		cin >> N;
		answer = 0;
		vec.clear();
		duplePerm();
		cout << answer << '\n';
	}

}