#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPlace(int iX, int iY, int iSize, const vector<vector<string>>& park)
{
    for(int i = iY; i < iY + iSize; i++)
    {
        for(int j = iX; j < iX + iSize; j++)
        {
            if(park[i][j] != "-1")
                return false;
        }
    }
    
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    
    sort(mats.begin(), mats.end(), greater<int>());
    
    int iRow = park.size();
    int iCol = park[0].size();
    
    for(int i = 0; i < mats.size(); i++)
    {
        int iSize = mats[i];
        
        if(iSize > iRow || iSize > iCol)
            continue;
        
        for(int j = 0; j <= park.size() - iSize; j++)
        {
            for(int k = 0; k <= park[0].size() - iSize; k++)
            {
                if(isPlace(k, j, iSize, park))
                    return iSize;
            }
        }
    }
    
    return -1;
}