#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer=1;
    int start=1;
    int end =1;
    int sum=1;
    
    while(1){
        
        if(start==((n/2)+1))break;
        
        if(sum==n){
            answer++;
            sum-=start;
            start++;
        }
        else if(sum>n){
            sum-=start;
            start++;
        }
        else{
            end++;
            sum+=end;
        }
    }
    return answer;
}