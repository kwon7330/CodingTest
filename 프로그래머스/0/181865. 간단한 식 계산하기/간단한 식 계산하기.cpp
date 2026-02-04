#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    string strTemp;
    int iValue1 = 0;
    int iValue2 = 0;
    char cOperator = 0;
    
    for(int i = 0; i < binomial.size(); i++)
    {
        if(binomial[i] != '+' && binomial[i] != '-' && binomial[i] != '*')
            strTemp += binomial[i];
        else
        {
            iValue1 = stoi(strTemp);
            strTemp = "";
            cOperator = binomial[i];
        }
        
    }
    iValue2 = stoi(strTemp);
    
    cout << iValue1 << " " << iValue2 << endl;
    
    if(cOperator == '+')
        answer = iValue1 + iValue2;
    else if(cOperator == '-')
        answer = iValue1 - iValue2;
     else if(cOperator == '*')
        answer = iValue1 * iValue2;
    
    return answer;
}