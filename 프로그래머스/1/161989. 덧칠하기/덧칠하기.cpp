#include <string>
#include <vector>
//#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    // 벽을 칠하는게 아니라 칠한걸 관리하는 부분으로 관점을 바꿔보자
    
    int iPainted = 0;
    
    for(int i = 0; i < section.size(); i++)
    {
        if(section[i] >= iPainted)
        {
            answer++;
            iPainted = section[i] + m;
            //cout << "LastPainted : " << iPainted << endl;
            //cout << section[i] << endl;
        }
    }
    
    return answer;
}