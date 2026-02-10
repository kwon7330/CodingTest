#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    // 저장된 번호의 약수의 개수가 구매 가능하다
    // but 제한수치 가 있을시 제한 수치를 초과하면 구매 불가능 또한 공격력 1당 1kg일때 필요한 철의 무게를 반환
    
    // 시간초과
    
    for(int i = 1; i <= number; i++)
    {
        int iAttack = 0;
        
        for(int j = 1; j <= sqrt(i); j++)
        {
            if(i % j == 0)
            {
                if(j * j == i)
                    iAttack++;
                else
                    iAttack += 2;
            }
        }
            
        
        if(limit < iAttack)
            answer += power;
        else
            answer += iAttack;
        
    }
    
    return answer;
}