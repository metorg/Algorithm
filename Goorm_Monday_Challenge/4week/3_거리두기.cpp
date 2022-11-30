#include <iostream>

using namespace std;
// start 2:32 end 3:50 1시간 18분 소요
// dp 점화식 세우는 연습을 더 해야겠다.
// key point: 각자리의 경우의 수를 생각해가며 dp의 기억해 가야한다.
int main() {
	
	long long  n;
	long long dp[100001][5];
	long long mod =100000007;
	long long answer=0;
	
	cin>>n;
	for(int i=0;i<5;i++)dp[1][i]=1;
	
	for(int i=2;i<=n;i++){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4])%mod;
		dp[i][1]=(dp[i-1][0]+dp[i-1][2]+dp[i-1][3])%mod;
		dp[i][2]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][3]+dp[i-1][4])%mod;
		dp[i][3]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mod;
		dp[i][4]=(dp[i-1][0]+dp[i-1][2])%mod;
	}
	
	for(int i=0;i<5;i++)answer+=dp[n][i];
	
	cout<<answer%mod;
	
	
}
