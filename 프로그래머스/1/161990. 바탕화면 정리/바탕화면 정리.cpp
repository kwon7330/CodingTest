#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    // 바탕화면의 상태를 나타낸 문자 배열 wallpaper
    // 빈칸은 . 파일이 있는 칸은 #
    // 파일을 선택 및 삭제 가능 최소한의 이동거리를 갖는 한 번의 드래그로 모든 파일을 삭제해서 지움
    // 점 S(lux, luy)에서 점 E(rdx, rdy)로 드래그를 할 때, "드래그 한 거리"는 |rdx - lux| + |rdy - luy|로 정의합니다.
    
    
    // 첫번째, 마지막으로 발견되는 #은 y 축 고정
    // 중간 중간 x축은 사이즈를 비교하며 갱신
    // S의 X축 보다 작으면 X축 갱신 S의 Y축 보다 작으면 Y축 갱신
    
    
    int iMinX = wallpaper[0].size();
    int iMinY = wallpaper.size();
    
    int iMaxX = 0;
    int iMaxY = 0;
    
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0; j < wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                iMinX = min(iMinX, j);
                iMinY = min(iMinY, i);
              
                iMaxX = max(iMaxX, j);
                iMaxY = max(iMaxY, i);
            }
        }
    }
    
    answer = {iMinY,iMinX,iMaxY + 1,iMaxX + 1};
    
    return answer;
}