#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    
    long long answer = 0;
    priority_queue<long long> pq;
    
    for(int i=0;i<works.size();i++){
        pq.push(works[i]);
    }
    for(int i=0;i<n;i++){
        long long tmp=pq.top()-1;
        pq.pop();
        pq.push(tmp);
    }
    while(!pq.empty()){
        if(pq.top()>0){
        answer+=pq.top()*pq.top();
        }
        pq.pop();
    }
    
    return answer;
}