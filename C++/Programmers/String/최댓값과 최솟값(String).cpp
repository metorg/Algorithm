#include <string>
#include <vector>
#include<string>
#include<algorithm>

using namespace std;

string solution(string s){
    
    string answer="";
    string stmp="";
    vector<int> v;
   
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            v.push_back(stoi(stmp));
            stmp="";
        }
        else stmp+=s[i];   
    }
   
    v.push_back(stoi(stmp));
    sort(v.begin(),v.end());

    answer+=to_string(v[0]);
    answer+=' ';
    answer+=to_string(v[v.size()-1]);
    
    return answer;
}