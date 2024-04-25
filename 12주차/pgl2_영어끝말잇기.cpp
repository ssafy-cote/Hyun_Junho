#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    unordered_set<string> set;

    int turn = 0;
    int curHuman = 0;
    char lastWord = words[0][0];

    for (int i = 0; i < words.size(); i++)
    {
        curHuman = i % n;

        if(!curHuman)
            turn++;
   
       if(words[i].size() == 1 ||
           words[i][0] != lastWord || 
           !set.insert(words[i]).second)
       {
           answer = { curHuman+1, turn };
           break;
       }

       lastWord = words[i][words[i].size() - 1];
    }

    return answer;
}