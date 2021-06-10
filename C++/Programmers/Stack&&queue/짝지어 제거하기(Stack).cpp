#include <iostream>
#include<string>
#include<stack>

using namespace std;

int solution(string s)
{    
    stack<char> st;
    int answer = -1;
   
    for(int i=0;i<s.size();i++){
        
        if(!st.empty()&&st.top()==s[i]){
            st.pop();
            continue;
        } 
        st.push(s[i]);
                
    }
    if(!st.empty())answer=0;
    else answer=1;

    return answer;
}