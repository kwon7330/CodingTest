#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    stack<char> Stk;
    
    for(int i = 1; i < food.size(); i++)
    {
       int iSize = food[i] / 2;
        
        for(int j = 0; j < iSize; j++)
        {
            answer.push_back(i + 48);
            Stk.push(i + 48);
            
        }
  
    }

    answer.push_back(0 + 48);
    int iStkSize = Stk.size();
    for(int i = 0; i < iStkSize; i++)
    {
        cout << Stk.top() << endl;
        answer.push_back(Stk.top());
        Stk.pop();
    }
    
    
    
    return answer;
}