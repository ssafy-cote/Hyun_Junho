#include <iostream>

#include <string>

using namespace std;
int cnt = -1;
int g_answer = -1;
char c[5] = { 'A', 'E', 'I', 'O', 'U' };
string g_curWord = "";

void dfs(string s, string& word)
{
    cnt++;

    if(s == word)
    {
        g_answer = cnt;
        return;
    }
        
    if (s.size() >= 5)
        return;

    for (int i = 0; i < 5; i++)
    {
        //cout << s + c[i] << '\n';
        dfs(s + c[i], word);        
        
        if (g_answer > 0)
            break;
    }
}

int solution(string word) {
    dfs(g_curWord, word);
    return cnt;
}

int main()
{
    cout << solution("EIO");
}