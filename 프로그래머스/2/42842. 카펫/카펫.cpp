#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
     int iSum = brown + yellow;

    for(int i = 1; i <= iSum; i++)
    {
        if(iSum % i != 0) 
            continue;

        int iCol = i;
        int iRow = iSum / i;

        if((iRow - 2) * (iCol - 2) == yellow)
        {
            answer.push_back(iRow);
            answer.push_back(iCol);
            break;
        }
    }
    return answer;
}