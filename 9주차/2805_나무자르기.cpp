#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

/*
������ ��    N    1~100��
������ ����    M    1~20��
���� ���̰� 10���̴� -> n�� Ž���ص� �ð��ʰ��� ����.

�ּ� M���� �������� ���� ���ܱ��� ���� H

1. �迭�� �Է¹޴´�.
    1-1. �Է¹����鼭 min max�� �����Ѵ�.

2. �̺�Ž���� �����Ѵ�.

    while(start > end)
    2-1 ���� ���� ������ �������� ������ ������. (half)

        int sum
    2-2 i �ݺ����� ���� ������ �����Ѵ�.
        2-2-1 arr[i]�� half�� ���� �� 0�� �ƴϸ�,
                sum += ����

    2-3 �ݺ����� ������ sum�� Ȯ���Ѵ�.
        2-3-1 sum�� M���� ������(������ ���ڸ���)
            half += half /2

        2-3-2 sum�� K�� ������ �ٷ� ������ ��ȯ�Ѵ�.

        //
        2-3-3 sum�� K���� ũ��(������ ������)
            answer�� half�� ���ϰ� �� ������ �ִ´�.
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

        //������ ���ڸ� �� ���̸� ��������Ѵ�.
        //end�� �����ش�.
        if (sum < M)
        {
            //mid���� �����Ƿ�  -1�� ���ش�?
            end = mid - 1;
        }
        else if (sum >= M)
        {
            //������ ��ĥ �� �� ���� �� �ִ��� ����.
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