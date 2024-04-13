#include <iostream>

#include <string>
#include <vector>
#include <utility>

using namespace std;

//��������
int minDist;
const int dir[2]{ 1, -1 };
const int alphabetSize = 26;

//������ ���ĺ����� �Ÿ� ����
string g_name;
vector<int> input;
vector<bool> isVisited;

void checkPointer(pair<int, int>& cursor, int size)
{
    cursor.first %= size;

    if (cursor.second < 0)
        cursor.second = size - 1;
}

bool checkVisit(vector<bool>& visit)
{
    for (bool b : visit)
        if (!b)
            return false;

    return true;
}

void dfs(int idx)
{
    for (int i : dir)
    {
        int cnt = 0;
        int nxtIdx = idx;
        while (true)
        {
            //��������
            if (checkVisit(isVisited))
            {
                int sum = 0;
                for (int i : input)
                    sum += i;

                if (sum < minDist)
                    minDist = sum;

                return;
            }

            cnt++;
            nxtIdx += i;

            if (nxtIdx < 0)
                nxtIdx = g_name.size() - 1;

            nxtIdx %= g_name.size();

            if (isVisited[nxtIdx] || g_name[nxtIdx] == 'A')
            {
                isVisited[nxtIdx] = true;
                continue;
            }

            isVisited[nxtIdx] = true;
            input.push_back(cnt);
            dfs(nxtIdx);
            isVisited[nxtIdx] = false;
            input.pop_back();

            break;
        }     
    }
}

int solution(string name) {
    int answer = 0;
 
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == 'A')
            continue;

        pair<int, int> cursor = { 0, 0 };
        while (1)
        {            
            cursor.first++;
            cursor.second--;
            answer++;
            checkPointer(cursor, alphabetSize);

            if ('A' + cursor.first == name[i] || 'A' + cursor.second == name[i])
                break;
        }
    }

    //�¿� Ž�� �ּҰŸ�
    minDist = 2147483647;
    g_name = name;
    isVisited.resize(name.size());
    isVisited[0] = true;
    input.push_back(0);
    
    if (!answer)
        return answer;

    dfs(0);    
    return answer+minDist;
}

int main()
{
    cout << solution("AAAAAAA");
}