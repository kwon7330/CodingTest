#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int,int>> q; 
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }
    
    int order = 0;
    
    while (!q.empty()) 
    {
        auto Current = q.front();
        q.pop();
        
        
        bool isHigher = false;
        queue<pair<int,int>> temp = q;
        
        while (!temp.empty()) 
        {
            if (temp.front().first > Current.first) 
            {
                isHigher = true;
                break;
            }
            temp.pop();
        }
        
        if (isHigher) 
            q.push(Current);
        
        else 
        {
            order++;
            if (Current.second == location) 
                return order; 
        }
    }
    
    return order;
}