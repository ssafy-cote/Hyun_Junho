#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	
	cin >> N >> M;
	
	vector<int> vec(M);
	int answer = 0;

	//빗물의 높이를 입력받는다.
	for (int i = 0; i < M; i++)
		cin >> vec[i];

	for (int i = 0; i < M-1; i++)
	{
		//타일이 0이 아닐때만 체크한다.
		if (vec[i])
		{
			int height = vec[i]+1;
			while (height--)
			{
				for (int j = i + 1; j < M; j++)
				{
					//다음 타일이 기존 타일보다 높거나 같은 타일을 만났을 때 빗물을 채워준다.
					if (vec[j] >= height)
					{
						answer += j - i - 1;
						break;
					}
				}
			}
		}
	}
	cout << answer;

}