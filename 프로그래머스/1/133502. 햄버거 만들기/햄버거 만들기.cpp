#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    // 1 2 3 1 순으로 햄버거 완성
    stack<int> stk;
    
    
    for(int i = 0; i < ingredient.size(); i++)
    {
        stk.push(ingredient[i]);
        
        if(stk.size() >= 4)
        {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            int c = stk.top();
            stk.pop();
            int d = stk.top();
            stk.pop();
            
            //cout << a << b << c << d << endl;
            
            if(d == 1 && c == 2 && b == 3 && a == 1)
                answer++;
            else
            {
                stk.push(d);
                stk.push(c);
                stk.push(b);
                stk.push(a);
            }
            
            
        }
    }
   
    
    return answer;
}