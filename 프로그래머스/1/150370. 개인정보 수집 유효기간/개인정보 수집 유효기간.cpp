#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


int ChangeDate(const string& strDate)
{  
    string strYear = strDate.substr(0,4);
    string strMonth = strDate.substr(5,2);
    string strDay = strDate.substr(8,2);
    
    return stoi(strYear) * 12 * 28 + stoi(strMonth) * 28 + stoi(strDay);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char,int> Period;
    
    int iToday = ChangeDate(today);
    
    for(int i = 0; i < terms.size(); i++)
    {
        char cType = terms[i][0];
        int iPeriod = stoi(terms[i].substr(2));
        Period.emplace(cType,iPeriod);
    }
    
    for(int i = 0; i < privacies.size(); i++)
    {
        string strPriDate = privacies[i].substr(0,10);
        char cType = privacies[i][11];
        
        int iDay = ChangeDate(strPriDate);
        
        int iTemp = iDay + Period[cType] * 28;
        
        if(iTemp <= iToday)
            answer.push_back(i + 1);
            
    }
    
    
    
    
    
    return answer;
}