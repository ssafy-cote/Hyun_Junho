#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> stack;

    //i = i초
    for (int i = 0; i < prices.size(); i++)
    {
        //가격이 떨어지면 
        while (!stack.empty() && prices[i] < prices[stack.top()])
        {
            answer[stack.top()] = i - stack.top();

            stack.pop();
        }
        stack.push(i);
    }

    while (!stack.empty())
    {
        answer[stack.top()] = (int)prices.size() - stack.top() - 1;
        stack.pop();
    }
    return answer;    
}

int main()
{
    vector<int> v = { 1, 2, 3, 2, 3 };
    solution(v);
}