#include <iostream>

#include <string>
#include <vector>
#include <math.h>

using namespace std;

//���� ���ڸ� �������� ��ȯ�Ѵ�.

//¦���϶� : �� ���ڸ��� �׻� 0�̹Ƿ� 1�� �����ش�.
//Ȧ���϶� : �ǳ��ڸ� ~ ù°�ڸ����� ���� 0�� ã�´�. 
//�� 0�� 1�� �ٲٰ� ���� �ڸ� 1�� 0���� �ٲ۴�.

const int maxSize = 128;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long i : numbers)
    {
        int idx = maxSize-1;
        long long num = i;

        //¦���϶�
        if (i % 2 == 0)
        {
            answer.push_back(i + 1);
            continue;
        }
 
        //Ȧ���϶�
        bool arr[maxSize] = {};
        while (i)
        {
            arr[idx] = i % 2;
            i /= 2;
            --idx;
        }

        for (int i = maxSize-1; i >= 0; i--)
        {
            if (!arr[i])
            {
                arr[i] = 1;
                arr[i + 1] = 0;
                break;
            }
        }

        long long num2 = 0;
        num = 0;
        for (int i = 0; i < maxSize; i++)
        {
            num = arr[maxSize - 1 - i];
            if (!num)
                continue;

            num2 += (long long)(num * pow(2, i));
        }
        answer.push_back(num2);
    }

    return answer;
}

int main()
{
    vector<long long> num = { 17592186044415 };
    
    num = solution(num);
    for (long long i : num)
        cout << i << '\n';

}