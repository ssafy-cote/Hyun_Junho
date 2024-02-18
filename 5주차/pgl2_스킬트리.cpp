#include <iostream>
#include  <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    //�ش� ���ڰ� ����Ű�� �ε������� �տ������� �Ұ����ϴ�.
    for (string s : skill_trees)
    {
        int idx = 0;
        for (char c : s)
        {
            if (skill.find(c) != string::npos)
            {
                int findIdx = skill.find(c); //ã�� �ε��� ��
                
                //��ųƮ���� �ش�� ��ų�� ���Դµ� ���� ��ų���� ����Ű�� �ε������� �ռ� ����ִٸ� �߸��� ��ġ�̴�.
                if (skill[findIdx] != skill[idx]) 
                {
                    answer--;
                    break;
                }
                else
                    idx++;
            }
        }
            answer++;
    }
    return answer;
}

int main()
{
    string skill = "CBD";

    vector<string> skillTrees = {"BACDE", "CBADF", "AECB", "BDA"};

    cout << solution(skill, skillTrees);
}