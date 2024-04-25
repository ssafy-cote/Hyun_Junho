#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

/*
나무의 수    N    1~100만
나무의 길이    M    1~20억
나무 길이가 10억이다 -> n번 탐색해도 시간초과가 난다.

최소 M개를 가져가기 위한 절단기의 높이 H

1. 배열을 입력받는다.
    1-1. 입력받으면서 min max를 저장한다.

2. 이분탐색을 진행한다.

    while(start > end)
    2-1 제일 높은 범위를 기준으로 반으로 나눈다. (half)

        int sum
    2-2 i 반복문을 돌며 나무를 수집한다.
        2-2-1 arr[i]에 half를 했을 때 0이 아니면,
                sum += 길이

    2-3 반복문이 끝나고 sum을 확인한다.
        2-3-1 sum이 M보다 작으면(나무가 모자르면)
            half += half /2

        2-3-2 sum이 K와 같으면 바로 정답을 반환한다.

        //
        2-3-3 sum이 K보다 크면(나무가 많으면)
            answer와 half를 비교하고 더 작은걸 넣는다.
            half -= half /2

*/

const int treeHeight = 2000000000;
int N, M;
int maxHeight = 0;
vector<int> vec;

void binarySearch(int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            int num = vec[i] - mid;
            
            if (num > 0)
                sum += num;
        }

        //나무가 모자를 때 높이를 낮춰줘야한다.
        //end를 낮춰준다.
        if (sum < M)
        {
            //mid까지 봤으므로  -1을 해준다?
            end = mid - 1;
        }
        else if (sum >= M)
        {
            //나무가 넘칠 때 더 줄일 수 있는지 본다.
            start = mid + 1;
            maxHeight = max(maxHeight, mid);
        }
    }
}

int main()
{
    cin >> N >> M;
    vec.resize(N);
   
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    binarySearch(0, treeHeight);
    cout << maxHeight;
}