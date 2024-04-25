#include <iostream>

#include <string>
#include <vector>
#include <math.h>

using namespace std;

//받은 숫자를 이진수로 변환한다.

//짝수일때 : 맨 끝자리가 항상 0이므로 1만 더해준다.
//홀수일때 : 맨끝자리 ~ 첫째자리까지 가서 0을 찾는다. 
//이 0을 1로 바꾸고 다음 자리 1을 0으로 바꾼다.

const int maxSize = 128;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long i : numbers)
    {
        int idx = maxSize-1;
        long long num = i;

        //짝수일때
        if (i % 2 == 0)
        {
            answer.push_back(i + 1);
            continue;
        }
 
        //홀수일때
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