#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int iZeroCount = 0;
    int iCount = 0;
    
    while (s != "1")
    {
        int iBeforeSize = s.size();

        s.erase(remove(s.begin(), s.end(), '0'), s.end());

        int iAfterSize = s.size();

        iZeroCount += (iBeforeSize - iAfterSize);

        int ilength = iAfterSize;
        s = "";

        while (ilength > 0)
        {
            s = char(ilength % 2 + '0') + s;
            ilength /= 2;
        }

        iCount++;
    }

    answer.push_back(iCount);
    answer.push_back(iZeroCount);

    return answer;
}