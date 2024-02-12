#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1105~
/*
- ��ȣ�� ���� �ٸ� L���� ���ĺ� �ҹ���.
- ��ȣ�� �ּ� 1���� ����(aeiou), �ּ� 2���� �������� �����Ǿ��ִ�.
- ���ĺ��� ���������� �迭�ȴ�.
- ����������� �����Ǵ� C���� ���ĺ�

���ĺ��� �ҹ���, �ߺ��� ����.

���μ���

- L,C�� �Է¹޴´�.
- �ݺ����� ���� C�� ���ĺ� ������ �Է¹޴´�.
- �Է¹���  C������ �����Ѵ�.
- cCl�� �����Ѵ�.
-���� �� ������ ������ ������ ������ ����Ѵ�.
- ���� �� ���ǿ� �´� ������ ����Ѵ�.

*/

int L, C;// ���� �ٸ� L���� ���ĺ�, �ܾ� �ĺ� C
vector<char> passwordKey;
char input[16];

/*
��� �Ű������� ����, ���� ���ڸ� �־��־����� ��� ���� �����Ͽ� ����.
char �迭�� ����� �����ֱ� ���� �����Ҵ��� ���־����� ���� ���� ����.
*/

void Comb(int dep, int cnt)
{
	//�� ���� ���ڿ� cnt�� �־ �� �ȵƴ�.
	if (dep == L)
	{
		int aeiou = 0; //����
		int word = 0; //����

		//������ 2�� �̻�, ������ 1�� �̻��� �ܾ ����Ѵ�.
		for (int i = 0; i < L; i++)
		{
			if (input[i] == 'a' || input[i] == 'e'
				|| input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
				aeiou++;
			else
				word++;
		}

		//�� input �迭�� �ִ��� 16���� �����µ� ������ ����� ���ڱ����� ���Դ�.
		if (aeiou > 0 && word > 1)
			cout << input << '\n';

		return;
	}

	//�� ó���� C������ �ƴ� L������ �ؼ� �೵��.
	for (int i = cnt; i < C; i++)
	{
		input[dep] = passwordKey[i]; //��ǲ�� dep��°�� i��°, cnt�� ȥ������ ����
		Comb(dep + 1, i + 1);
	}
}

int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char c;
		cin >> c;
		passwordKey.push_back(c);
	}

	sort(passwordKey.begin(), passwordKey.end());

	Comb(0, 0);
}