#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    unordered_map<string,int> Map; //{{"mumu",0},{"soe",1},{"poe",2},{"kai",3},{"mine",4}};
    
    for(int i = 0; i < players.size(); i++)
    {
        //Map.emplace(players[i],i);
        Map[players[i]] = i;
    }
    
    for(int i = 0; i < callings.size(); i++)
    {
        string strName = callings[i];
        int iIndex = Map[strName];
        string strFrontName = players[iIndex-1];
        
        swap(players[iIndex],players[iIndex-1]);
        
        Map[strFrontName]++;
        Map[strName]--;        
    }
    
    
    for(int i = 0; i < players.size(); i++)
    {
        //cout << players[i] << " ";
    }
    
    
   //for(int i = 0; i < players.size(); i++)
   //{
       //answer.push_back(players[i]);
   //}
    
    return players;
}