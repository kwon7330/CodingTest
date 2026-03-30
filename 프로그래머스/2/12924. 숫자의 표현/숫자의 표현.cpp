#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int iLeft = 1;
    int iRight = 1;
    int iSum = 1;
    
    while(iLeft <= n)
    {
        if(iSum < n)
        {
            iRight++;
            iSum += iRight;
        }
        else if(iSum > n)
        {
            iSum -= iLeft;
            iLeft++;
        }
        else
        {
            answer++;
            iSum -= iLeft;
            iLeft++;
        }
    }
        
    return answer;
}