#include <iostream>
#include <vector>

using namespace std;

/*
�� ����� ���� 100%�϶� ���񽺸� �����Ѵ�.

�ڿ� �ִ� ����� �տ� �ִ� ��ɺ��� ���� ���ߵ� �� �ְ� 
���� ����� ������ �� ���� �����ȴ�.


���μ���

- for���� ���� progress�� ��ȸ�Ѵ�.
- �۾��� ��� 100%�� �̷�����Ƿ� 100-progresses[i]�� �Ͽ� ���� ������ term�� ���Ѵ�.
- ù �۾��� �Ⱓ�� ����� ���̹Ƿ� progress�� 1�� ���  term�� �Ⱓ�� ����Ѵ�.
���� term�� speed�� ������ �������� ���Ҵٸ� ���� Ƚ���� �ѹ� �� �÷��ش�.
- while���� ���� �ش� �Ⱓ ���� ������ ���μ������� ��� ī��Ʈ�ϰ� i���� ���������ش�.
- while���� ������ ������ ���μ������� �����Ѵ�. 
*/

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    
    for (int i = 0; i < progresses.size(); i++)
    {
        int term = 100 - progresses[i];
        int progress = 1;

        //�Ⱓ
        term% speeds[i] ? term = term / speeds[i] + 1 : term = term / speeds[i];

        //i�� ++i�� ����߾ while���� ������ for������ �̾��� �� i�� �ѹ� �� �����ؼ� ������ �̻�������.
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