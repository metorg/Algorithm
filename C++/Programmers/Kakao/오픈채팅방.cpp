#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

unordered_map<string,string> um;
vector<pair<string,int>> result;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(int i=0;i<record.size();i++){
    
        istringstream ss(record[i]);    
        string sb;        
        vector<string> x;
        
        while(getline(ss,sb,' ')){
            x.push_back(sb);            
        }
        
        if(x[0]=="Enter"){
            result.push_back({x[1],1});
            um[x[1]]=x[2];
        }
        else if(x[0]=="Change"){
            um[x[1]]=x[2];
        }
        else{
            result.push_back({x[1],2});
        }
            
    }
    for(int i=0;i<result.size();i++){        
        if(result[i].second==1)
            answer.push_back(um[result[i].first]+"님이 들어왔습니다.");
        
        else
            answer.push_back(um[result[i].first]+"님이 나갔습니다.");        
    }
    return answer;
}
