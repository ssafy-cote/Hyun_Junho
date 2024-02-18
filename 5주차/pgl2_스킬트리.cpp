#include <iostream>
#include  <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    //해당 문자가 가리키는 인덱스보다 앞에있으면 불가능하다.
    for (string s : skill_trees)
    {
        int idx = 0;
        for (char c : s)
        {
            if (skill.find(c) != string::npos)
            {
                int findIdx = skill.find(c); //찾은 인덱스 비교
                
                //스킬트리에 해당된 스킬이 나왔는데 현재 스킬에서 가리키는 인덱스보다 앞서 들어있다면 잘못된 배치이다.
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