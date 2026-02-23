#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> Target = {"aya", "ye", "woo", "ma"};
   
    for(int i = 0; i < babbling.size(); i++)
    {
        string str = babbling[i];
        string strPrev = "";
        bool isAble = true;

        while(!str.empty())
        {
            bool isMatched = false;
            
            for(int j = 0; j < Target.size(); j++)
            {
                if(str.substr(0, Target[j].size()) == Target[j] && strPrev != Target[j])
                {
                    strPrev = Target[j];
                    str = str.substr(Target[j].size());
                    isMatched = true;
                    break;
                }
            }

            if(!isMatched)
            {
                isAble = false;
                break;
            }
        }
       
        if(isAble)
            answer++;
         cout <<"answer : " <<  answer << endl;
    }

    return answer;
}