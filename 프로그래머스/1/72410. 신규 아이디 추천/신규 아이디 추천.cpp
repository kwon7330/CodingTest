#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

string solution(string new_id) {
    
    stack<char> Stk;
    int iChangeAlpha = 'a' - 'A';

    for(int i = 0; i < new_id.size(); i++)
    {
        char c = new_id[i];
    
        if(c >= 'A' && c <= 'Z')
            c += iChangeAlpha;
        
        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.')
        {
            
            if(!Stk.empty() && Stk.top() == '.' && c == '.')
                continue;

            Stk.push(c);
        }
    }

    
    string answer = "";
    while(!Stk.empty())
    {
        answer = Stk.top() + answer;
        Stk.pop();
    }

    
    if(!answer.empty() && answer.front() == '.')
        answer.erase(0,1);

    
    if(!answer.empty() && answer.back() == '.')
        answer.pop_back();

    
    if(answer.empty())
        answer = "a";

    
    if(answer.size() >= 16)
    {
        answer.erase(15);

        if(answer.back() == '.')
            answer.pop_back();
    }

    
    while(answer.size() < 3)
        answer += answer.back();

    return answer;
}