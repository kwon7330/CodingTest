#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,vector<int>,greater<int>> Pq;
    
    for(int i = 0; i < scoville.size(); i++)
    {
        Pq.push(scoville[i]);
    }
    
    int iFirst = 0;
    // 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
    while(Pq.size() >= 2 && iFirst < K)
    {
        
        iFirst = Pq.top();
        
        if(iFirst >= K)
            return answer;
        Pq.pop();
        
        //cout << "First:"  << iFirst << endl;
        
        int iSecond = Pq.top();
        Pq.pop();
        
        //cout << "Second:" << iSecond << endl;
        
        int iNewScovil = iFirst + (iSecond * 2);
        
        //cout << "NewScovil:" << iNewScovil << endl;
        
        Pq.push(iNewScovil);
        
        answer++;
    }

    if(Pq.top() <= K)
        answer = -1;
    
    return answer;
}