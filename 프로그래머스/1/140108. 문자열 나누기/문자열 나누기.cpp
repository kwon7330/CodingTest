#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    int iSame = 0;
    int iDiff = 0;
    int iTarget = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(iSame == 0)
        {
            iTarget = s[i];
            iSame = 1;
            answer++;
        }
        else
        {
            if(s[i] == iTarget)
                iSame++;
            else
                iDiff++;
        }
    
        if(iSame == iDiff)
        {
            iSame = 0;
            iDiff = 0;
        }    
    }

    return answer;
}