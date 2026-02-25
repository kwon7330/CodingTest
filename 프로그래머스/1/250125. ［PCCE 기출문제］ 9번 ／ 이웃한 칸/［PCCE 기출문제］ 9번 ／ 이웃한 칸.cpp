#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
   
    int iRow = board.size();
    int iCol = board[0].size();

    if(h - 1 >= 0 && board[h - 1][w] == board[h][w])
        answer++;
    if(h + 1 < iRow && board[h + 1][w] == board[h][w])
        answer++;
    if(w - 1 >= 0 && board[h][w-1] == board[h][w])
        answer++;
    if(w + 1 < iCol && board[h][w+1] == board[h][w])
        answer++;
    
    
    return answer;
}