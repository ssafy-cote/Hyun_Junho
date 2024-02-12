#include <iostream>
#include <vector>

using namespace std;

/*
각 기능은 진도 100%일때 서비스를 제공한다.

뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고 
앞의 기능이 배포될 때 같이 배포된다.


프로세스

- for문을 돌며 progress를 순회한다.
- 작업은 모두 100%로 이루어지므로 100-progresses[i]을 하여 남은 진행인 term을 구한다.
- 첫 작업의 기간은 계산할 것이므로 progress를 1로 잡고  term의 기간을 계산한다.
만약 term을 speed를 나누고 나머지가 남았다면 나눈 횟수를 한번 더 올려준다.
- while문을 돌며 해당 기간 내에 끝나는 프로세스들을 모두 카운트하고 i값을 증가시켜준다.
- while문이 끝나면 수집한 프로세스들을 삽입한다. 
*/

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    
    for (int i = 0; i < progresses.size(); i++)
    {
        int term = 100 - progresses[i];
        int progress = 1;

        //기간
        term% speeds[i] ? term = term / speeds[i] + 1 : term = term / speeds[i];

        //i를 ++i로 사용했어서 while문이 끝나고 for문으로 이어질 시 i를 한번 더 증가해서 로직이 이상해졌다.
        while (i+1 < progresses.size() && (speeds[i+1] * term)+progresses[i+1] >= 100)
        {
            i++;
            progress++;
        }        
        answer.push_back(progress);
    }

    return answer;
}

int main()
{
    vector<int> progresses = { 95, 90, 99,99,80,99 };
    vector<int> speeds = { 1, 1, 1,1,1,1 };

    vector<int> answer = solution(progresses, speeds);
    for (int i : answer)
        cout << i << '\n';
}