#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer=0;
    int dp[1000001]={1};
    
    for(int i=0;i<money.size();i++){
        for(int j=money[i];j<=n;j++)
            dp[j]+=dp[j-money[i]];
            
        
    }
    answer=dp[n];
    return answer;
}