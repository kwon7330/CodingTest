#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    //[t = 5, x = 1, y = 5]
    // 최대 체력  30
    // 공격시간 과 피해량 
    // 모든 공격이 끝난 직후 남은 체력을 return
    int iMaxHealth = health;
    
    int iT = bandage[0];
    int iHealPerTime = bandage[1];
    int iHeal = bandage[2];
    
    int iAttackIndex = 0;
    int iLastAttackTime = attacks.back()[0];
    int iHealTime = 0;
    
    for(int iTime = 1; iTime <= iLastAttackTime; iTime++)
    {
        if(iTime == attacks[iAttackIndex][0])
        {
            health -= attacks[iAttackIndex][1];

              if(health <= 0)
                return -1;
            
            iHealTime = 0;
            iAttackIndex++;
        }
        else
        {
            health += iHealPerTime;
            iHealTime++;

            if(iHealTime == iT)
            {
                health += iHeal;
                iHealTime = 0;
            }
            if(health >= iMaxHealth)
                health = iMaxHealth;
        }
    }
  
    answer = health;
    
    return answer;
}