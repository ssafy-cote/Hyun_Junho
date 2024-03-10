#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*강의 왼쪽에는 N개의 사이트, 오른쪽에는 M개의 사이트(M이 더 크거나 같다.)
*	M에서 N개를 선택하는 조합을 작성하면 될거같음 MCN
* 
*	  M!
* ----------
* (M-N)! * N!
*/

bool comp(int a, int b)
{
	return b < a; // left가 크면(false이면) 오른쪽으로 보낸다.
}

int main()
{
	int T, N, M;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;

		vector<int> vec;
		vector<int> vec2;

		//M! / N!
		//6! 4!
		for (int i = 0; i < N; i++)
		{
			vec.push_back(M - i);// M! 에서 (M-N)! 나눈 나머지들			
			vec2.push_back(N - i); //// N!
		}
			
		vector<bool> isUsed(vec2.size());

		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec2.size(); j++)
			{
				if (!isUsed[j] && vec2[j] != 1 && (vec[i] % vec2[j] == 0))
				{
					vec[i] /= vec2[j];	
					vec2[j] = 1;
					isUsed[j] = true;
				}
			}
		}

		long long answer = 1;

		for (int i = 0; i < vec.size(); i++)
		{
			answer *= vec[i];
		}

		for (int i = 0; i < vec2.size(); i++)
		{
			if (vec2[i] > 1)
				answer /= vec2[i];
		}
		cout << answer << '\n';
	}
	//매우 비효율적인 방식으로 짠듯, 나중에 개선해보기
}