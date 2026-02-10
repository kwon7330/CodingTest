#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int a, int b) {
    string answer[7] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };

    int Month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int iDays = 0;

    for (int i = 0; i < a - 1; i++)
        iDays += Month[i];

    iDays += (b - 1);

    
    return answer[iDays % 7];
}