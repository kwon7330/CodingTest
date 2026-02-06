#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    
    int answer = 0;
    
    while(n >= a)
    {
        int iCount = n / a;
        int iNew = iCount * b;
        int iRest = n % a;
        
        answer += iNew;
        
        n = iNew + iRest;
    }
    
    
    return answer;
}