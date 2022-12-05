#include <iostream>

//key point: dp[라운드 수][한명의 남은 구슬 개수] dp의 배열안에 넣을 조건들을 잘 생각해서 풀어보기

using namespace std;

int n,m,k;
int dp[1001][201];
int mod =1e8+7;

int main() {
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin>>n>>m>>k;
	
	for(int i=0;i<=k;i++){
		for(int j=0;j<=n+m;j++){
			dp[i][j]%=mod;
			
			if(j==0||j==n+m)dp[i][j]=1;
			
			if(0<j+1&&j+1<n+m)dp[i+1][j+1]+=dp[i][j];
			
			if(0<j&&j<n+m)dp[i+1][j]+=dp[i][j];
			
			if(0<j-1&&j-1<n+m)dp[i+1][j-1]+=dp[i][j];
		}
	}
	cout<<dp[k][n];
}
