#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*���� ���ʿ��� N���� ����Ʈ, �����ʿ��� M���� ����Ʈ(M�� �� ũ�ų� ����.)
*	M���� N���� �����ϴ� ������ �ۼ��ϸ� �ɰŰ��� MCN
* 
*	  M!
* ----------
* (M-N)! * N!
*/

bool comp(int a, int b)
{
	return b < a; // left�� ũ��(false�̸�) ���������� ������.
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
			vec.push_back(M - i);// M! ���� (M-N)! ���� ��������			
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
	//�ſ� ��ȿ������ ������� §��, ���߿� �����غ���
}