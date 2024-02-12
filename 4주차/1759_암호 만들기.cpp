#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1105~
/*
- 암호는 서로 다른 L개의 알파벳 소문자.
- 암호는 최소 1개의 모음(aeiou), 최소 2개의 자음으로 구성되어있다.
- 알파벳은 사전순으로 배열된다.
- 사용했으리라 추측되는 C가지 알파벳

알파벳은 소문자, 중복은 없다.

프로세스

- L,C를 입력받는다.
- 반복문을 돌려 C의 알파벳 각각을 입력받는다.
- 입력받은  C집합을 정렬한다.
- cCl로 조합한다.
-조합 중 모음의 개수와 자음의 개수도 기록한다.
- 리턴 시 조건에 맞는 조합을 출력한다.

*/

int L, C;// 서로 다른 L개의 알파벳, 단어 후보 C
vector<char> passwordKey;
char input[16];

/*
재귀 매개변수에 자음, 모음 인자를 넣어주었으나 계속 값이 증가하여 실패.
char 배열에 사이즈를 맞춰주기 위해 동적할당을 해주었으나 값이 깨져 실패.
*/

void Comb(int dep, int cnt)
{
	//■ 여기 인자에 cnt를 넣어서 잘 안됐다.
	if (dep == L)
	{
		int aeiou = 0; //모음
		int word = 0; //자음

		//자음이 2개 이상, 모음이 1개 이상인 단어만 출력한다.
		for (int i = 0; i < L; i++)
		{
			if (input[i] == 'a' || input[i] == 'e'
				|| input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
				aeiou++;
			else
				word++;
		}

		//■ input 배열을 최대인 16으로 잡아줬는데 조합한 출력이 숫자까지만 나왔다.
		if (aeiou > 0 && word > 1)
			cout << input << '\n';

		return;
	}

	//■ 처음에 C까지가 아닌 L까지로 해서 삑났다.
	for (int i = cnt; i < C; i++)
	{
		input[dep] = passwordKey[i]; //인풋의 dep번째는 i번째, cnt랑 혼동하지 말것
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