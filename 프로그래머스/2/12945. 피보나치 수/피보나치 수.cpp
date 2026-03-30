#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    if(n == 0)
        answer = 0;
    else if(n == 1)
        answer = 1;
    else
    {
        int iPrev1 = 0;
        int iPrev2 = 1;
        int iCurrent = 0;
        
        for(int i = 2; i < n + 1; i++)
        {
            iCurrent = (iPrev1 + iPrev2) % 1234567;
            iPrev1 = iPrev2;
            iPrev2 = iCurrent;
        }
        
        answer = iCurrent;
    }
        
    
    return answer;
}