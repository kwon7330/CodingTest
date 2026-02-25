#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    bool Alpha[26] = {false};
    
    for(int i = 0; i < skip.size(); i++)
    {
        
        for(int j = 0; j < 26; j++)
        {
            if(skip[i] == 'a' + j)
            {
                Alpha[j] = true;
            }
        }
    }

    
    for(int i = 0; i < s.size(); i++)
    {
        int iCount = 0;
        int iTarget = s[i] - 'a';
        while(iCount < index)
        {
            iTarget++;
            if(iTarget >= 26)
                iTarget = 0;

            if(!Alpha[iTarget])
                iCount++;
        }
        answer += iTarget + 'a';
    }
    
    return answer;
}