#include <string>
#include <vector>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    int iCountX[10] = {};
    int iCountY[10] = {};
    
    for(char c : X)
        iCountX[c - '0']++;
    
    for(char c : Y)
        iCountY[c - '0']++;
    
    for(int i = 9; i >= 0; i--)
    {
        int iMinCount = min(iCountX[i], iCountY[i]);
        
        for(int j = 0; j < iMinCount; j++)
            answer += (i + '0');
    }
    
    if(answer == "") return "-1";
    
    if(answer[0] == '0') return "0";
    
    return answer;
}