#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	
	cin >> N >> M;
	
	vector<int> vec(M);
	int answer = 0;

	//������ ���̸� �Է¹޴´�.
	for (int i = 0; i < M; i++)
		cin >> vec[i];

	for (int i = 0; i < M-1; i++)
	{
		//Ÿ���� 0�� �ƴҶ��� üũ�Ѵ�.
		if (vec[i])
		{
			int height = vec[i]+1;
			while (height--)
			{
				for (int j = i + 1; j < M; j++)
				{
					//���� Ÿ���� ���� Ÿ�Ϻ��� ���ų� ���� Ÿ���� ������ �� ������ ä���ش�.
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