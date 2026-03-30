#include <string>
#include <vector>

using namespace std;

int Count_NumOne(int iMaxNumber)
{
    int iCount = 0;
    
    while(iMaxNumber > 0)
    {
        if(iMaxNumber % 2 == 1)
            iCount++;
        
        iMaxNumber /= 2;
    }
    
    return iCount;
}


int solution(int n) {
    int answer = 0;
    int iTarget = Count_NumOne(n); 
    answer = n; 
    
    while(true)
    {
        answer++;
        if(Count_NumOne(answer) == iTarget)
        {
            break;
        }
    }
    
    return answer;
}