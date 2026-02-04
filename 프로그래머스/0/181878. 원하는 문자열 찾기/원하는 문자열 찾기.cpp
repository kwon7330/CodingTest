#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    //65 ~ 90 소문자
    //97 ~ 122 대문자
    for(int i = 0; i < myString.size(); i++)
    {
        if(myString[i] >= 'a' && myString[i] <= 'z')
            myString[i] -= 32;
    }
    
   for(int i = 0; i < pat.size(); i++)
    {
        if(pat[i] >= 'a' && pat[i] <= 'z')
            pat[i] -= 32;
    }
    

    for(int i = 0; i < myString.size(); i++)
    {
        if(myString.substr(i,pat.size()) == pat)
            return 1;
    }
    
    
    
    return answer;
}