#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> vec;
int answerA = 0;
int answerB = 0;
int minAbs = 2147483647;

/*
1. 배열 입력받기
2. start, end를 인자로 가진 투포인터 루프배열
	* start >= end가되면 반복문 탈출
	2-1. 두 용액의 특성값을 구한다. sum = vec[start] + vec[end]
		2-1-1. 특성값의 절대값으로 0에 가까운 수를 구한다.
		2-1-2. 특성값이 minAbs보다 작아졌다면 더 작은 오차가 나왔다는 뜻이므로 갱신해준다.
			2-1-2-1. 0이나온다면 정답으로 쳐도 되므로 반복문을 빠져나온다.

	★
	2-2
		특성값이 음수가 나오면 음수를 줄이기 위해 start를 증가시킨다.
		특성값이 양수가 나오면 양수를 줄이기 위해 end를 감소시킨다.
*/

void twoPointer(int start, int end)
{
	while (start < end)
	{
		int sum = vec[start] + vec[end];

		if (abs(sum) < minAbs)
		{
			minAbs = abs(sum);
			answerA = vec[start];
			answerB = vec[end];

			if (!sum)
				break;
		}

		if (sum < 0)
			start++;
		else if (sum > 0)
			end--;
	}
}

int main()
{
	cin >> N;
	
	vec.resize(N);

	for (int i = 0; i < N; i++)
		cin >> vec[i];
	
	twoPointer(0, N - 1);
	cout << answerA << " " << answerB;
}