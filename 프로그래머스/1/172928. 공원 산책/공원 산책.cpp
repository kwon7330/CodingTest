#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    
    vector<int> answer;
    
    int iX = 0, iY = 0;

    for(int i = 0; i < park.size(); i++)
    {
        for(int j = 0; j < park[i].size(); j++)
        {
            if(park[i][j] == 'S')
            {
                iY = i;
                iX = j;
            }
        }
    }

    int iDeltaX[4] = {0,0,-1,1};
    int iDeltaY[4] = {-1,1,0,0};

    for(int i = 0; i < routes.size(); i++)
    {
        char cDirection = routes[i][0];
        int iDistance = routes[i][2] - '0';

        int iDelta = 0;

        if(cDirection == 'N')
            iDelta = 0;
        else if(cDirection == 'S')
            iDelta = 1;
        else if(cDirection == 'W')
            iDelta = 2;
        else if(cDirection == 'E')
            iDelta = 3;

        int iCurrentX = iX;
        int iCurrentY = iY;

        bool isMove = true;

        for(int j = 0; j < iDistance; j++)
        {
            iCurrentX += iDeltaX[iDelta];
            iCurrentY += iDeltaY[iDelta];

            if(iCurrentX < 0 || iCurrentY < 0 || 
               iCurrentY >= park.size() || iCurrentX >= park[0].size())
            {
                isMove = false;
                break;
            }

            if(park[iCurrentY][iCurrentX] == 'X')
            {
                isMove = false;
                break;
            }
        }

        if(isMove)
        {
            iX = iCurrentX;
            iY = iCurrentY;
        }
    }

    answer.push_back(iY);
    answer.push_back(iX);

    return answer;
}