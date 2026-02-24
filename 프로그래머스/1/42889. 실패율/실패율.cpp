#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    vector<pair<float,int>> Failure;

    for(int i = 1; i <= N; i++)
    {
        int iNumPlayer = 0; 
        int iOnPlayer = 0;  

        for(int j = 0; j < stages.size(); j++)
        {
            if(i <= stages[j])
                iNumPlayer++;
            if(i == stages[j])
                iOnPlayer++;
        }

        float fFailRate = 0;

        if(iNumPlayer != 0)
            fFailRate = (float)iOnPlayer / iNumPlayer;

        Failure.push_back({fFailRate, i});
    }

    sort(Failure.begin(), Failure.end(), [](pair<float,int> a, pair<float,int> b)
    {
        if(a.first == b.first)
            return a.second < b.second; 
        return a.first > b.first;   
    });
    
    
    for(int i = 0; i < Failure.size(); i++)
        answer.push_back(Failure[i].second);

    return answer;
}
