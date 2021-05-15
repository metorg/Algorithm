#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    vector<int> answer;
    unordered_map<string,int> um;
    um[words[0]]++;
    
    for(int i=1;i<words.size();i++){
        char alpa=words[i-1][words[i-1].length()-1];
        
        if(alpa!=words[i][0]||um[words[i]]==1){            
            answer.push_back((i%n)+1);
            answer.push_back((i/n)+1);
            break;
        }
        
        else um[words[i]]++;
        
    }
    
    if(answer.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}