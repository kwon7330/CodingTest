#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> vecTemp;

    for(int i = 0; i < score.size(); i++)
    {
        vecTemp.push_back(score[i]);

        sort(vecTemp.begin(), vecTemp.end());

        if(vecTemp.size() > k)
            vecTemp.erase(vecTemp.begin()); 

        answer.push_back(vecTemp.front());
    }

    return answer;
}