#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    int answer = 1;
    vector<string> v;
    unordered_map<string,int> um;
      
    for(int i=0;i<clothes.size();i++)  um[clothes[i][1]]++;
    
    for(auto elem:um) answer*=(elem.second+1);
   
    return answer-1;
}