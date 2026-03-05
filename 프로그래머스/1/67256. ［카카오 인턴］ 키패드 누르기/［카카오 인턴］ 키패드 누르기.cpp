#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    pair<int,int> keypad[10] =
    {
        {3,1}, {0,0}, {0,1}, 
        {0,2}, {1,0}, {1,1}, 
        {1,2}, {2,0}, {2,1}, 
        {2,2}  
    };

    pair<int,int> Left = {3,0};  
    pair<int,int> Right = {3,2};  

    for(int i = 0; i < numbers.size(); i++)
    {
        
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            Left = keypad[numbers[i]];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += "R";
            Right = keypad[numbers[i]];
        }
        else
        {
            pair<int,int> Target = keypad[numbers[i]];

            int iDist_L = abs(Left.first - Target.first)
                      + abs(Left.second - Target.second);

            int iDist_R = abs(Right.first - Target.first)
                      + abs(Right.second - Target.second);

            if(iDist_L < iDist_R)
            {
                answer += "L";
                Left = Target;
            }
            else if(iDist_R < iDist_L)
            {
                answer += "R";
                Right = Target;
            }
            else
            {
                if(hand == "right")
                {
                    answer += "R";
                    Right = Target;
                }
                else
                {
                    answer += "L";
                    Left = Target;
                }
            }
        }
    }

    return answer;
}