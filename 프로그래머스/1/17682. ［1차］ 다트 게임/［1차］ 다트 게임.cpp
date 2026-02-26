#include <string>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    stack<int> Stk;
    
    for(int i = 0; i < dartResult.size(); i++)
    {
        if(dartResult[i] == '1' && i + 1 < dartResult.size() && dartResult[i + 1] == '0')
        {
            Stk.push(10);
            i++;
        }
        else if(dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            Stk.push(dartResult[i] - '0');
        }
        else if(dartResult[i] == 'S')
        {
            int iNum = Stk.top();
            Stk.pop();
            Stk.push(pow(iNum,1));
        }
        else if(dartResult[i] == 'D')
        {
            int iNum = Stk.top();
            Stk.pop();
            Stk.push(pow(iNum,2));
        }
        else if(dartResult[i] == 'T')
        {
            int iNum = Stk.top();
            Stk.pop();
            Stk.push(pow(iNum,3));
        }
        else if(dartResult[i] == '*')
        {
            int iNum = Stk.top();
            Stk.pop();
            iNum *= 2;
            
            if(!Stk.empty())
            {
                int iPrevNum = Stk.top();
                Stk.pop();
                iPrevNum *= 2;
                Stk.push(iPrevNum);
            }
            
            Stk.push(iNum);
        }
        else if(dartResult[i] == '#')
        {
            int iNum = Stk.top();
            Stk.pop();
            Stk.push(-1 * iNum);
        }
    }
    

    while (!Stk.empty()) 
    {
        answer += Stk.top();
        Stk.pop();
    }
    
    return answer;
}

  

