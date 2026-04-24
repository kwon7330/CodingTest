#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    
    int iMaxNum = -2147000000;
    int iMinNum = 2147000000;
    
    stringstream ss(s);
    int iNum;
    
    while (ss >> iNum) 
    {
        if (iNum > iMaxNum)
            iMaxNum = iNum;
        
        if (iNum < iMinNum)
            iMinNum = iNum;
    }
    
    answer = to_string(iMinNum) + " " + to_string(iMaxNum);
    
    return answer;
}