#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int sum,sum2;
    
    priority_queue< int, vector<int>, greater<int> > pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
   
    while(!pq.empty()){
        sum=pq.top();
        pq.pop();
        if(sum>=K||pq.empty())break;
        sum2=pq.top();
        pq.pop();
        pq.push(sum+(sum2*2));
        answer++;
    }
    
    if(pq.empty()&&sum<K)answer=-1;
    
    return answer;
}