#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    int MinPress[26] = {};
    
    for(int i = 0; i < 26; i++)
    {
        MinPress[i] = -1;
    }
    
    for(int i = 0; i < keymap.size(); i++)
    {
        for(int j = 0; j < keymap[i].size(); j++)
        {
            int iIndex = keymap[i][j] - 'A';
            
            //if(기존값 == -1 || 기존값 > 새값)
                //기존값 = 새값;
            
            if(MinPress[iIndex] == -1 || MinPress[iIndex] > j + 1)
                MinPress[iIndex] = j + 1;
        }
    }
    
    for(int i = 0; i < targets.size(); i++)
    {
        int iCount = 0;
        bool isPossible = true;
        
        for(int j = 0; j < targets[i].size(); j++)
        {
            int iIndex = targets[i][j] - 'A';
            
            if(MinPress[iIndex] == -1)
            {
                isPossible = false;
                break;
            }
            
            iCount += MinPress[iIndex];
        }
        
        if(isPossible)
            answer.push_back(iCount);
        else
            answer.push_back(-1);
    }
    
    return answer;
}