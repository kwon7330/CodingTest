#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    
    for(int idx = 0; idx < commands.size(); idx++)
    {
        int i = commands[idx][0];
        int j = commands[idx][1];
        int k = commands[idx][2];
        vector<int> vecTemp = {};
        for(i -= 1; i < j; i++)
        {
            vecTemp.push_back(array[i]);
        }
        sort(vecTemp.begin(),vecTemp.end());
        
        for(int i = 0; i < vecTemp.size(); i++)
            cout << vecTemp[i] << " ";
        cout << endl;
        
        answer.push_back(vecTemp[k-1]);
    }
    
  
    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    
    
    
    return answer;
}