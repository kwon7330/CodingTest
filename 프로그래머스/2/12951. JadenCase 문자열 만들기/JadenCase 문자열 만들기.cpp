#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++)
    {
        char c;
        
        if(s[i] >= 'A' && s[i] <= 'Z')
            c = s[i] + 32;
        else
            c = s[i]; 
        
        answer.push_back(c);
    }
    
    if (answer[0] >= 'a' && answer[0] <= 'z')
        answer[0] -= 32;
    
    
    for (int i = 0; i < answer.size() - 1; i++) 
    {
        if (answer[i] == ' ' && answer[i + 1] >= 'a' && answer[i + 1] <= 'z')
            answer[i + 1] -= 32;
    }
    
    return answer;
}