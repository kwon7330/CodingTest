#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    vector<string> strTable = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    string strTemp = {};
    string strResult = {};
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
           
           strResult += s[i];
            
        }
        else
        {
            strTemp += s[i];
             for(int j = 0; j < strTable.size(); j++)
            {
                if(strTemp == strTable[j])
                {
                    strResult += j + '0';
                    cout << "Temp :" << strTemp << endl;
                    strTemp.clear();
                }
            } 
        }
        
    }
    
    //cout << "Result : " << strResult << endl;
    
    answer = stoi(strResult);
    
    //cout << "answer : " << answer << endl;
    
    return answer;
}