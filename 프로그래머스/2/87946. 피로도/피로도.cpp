#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Dfs(vector<vector<int>> dungeons, vector<bool> visited, int iCurrentHp, int iCount, int& answer )
{
    answer = max(iCount,answer);
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(!visited[i] && iCurrentHp >= dungeons[i][0])
        {
            visited[i] = true;
            Dfs(dungeons,visited,iCurrentHp - dungeons[i][1],iCount+1,answer);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int iSize = dungeons.size();
    vector<bool> visited(iSize, false);
    Dfs(dungeons,visited,k,0,answer);
    
    return answer;
}