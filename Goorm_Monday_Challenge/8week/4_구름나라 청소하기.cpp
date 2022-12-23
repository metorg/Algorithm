#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dp[1002][50002];
int n, k, num1, num2;
vector<int> city[1002];
int cityTrash[1002];
int answer = 0;

void dfs(int cur,int prev){
	for(int i=0;i<=k;i++){
		if(dp[prev][i]){
			dp[cur][i]=1;
			if(i<=k)answer=max(answer,i);
			if(i+cityTrash[cur]<=k){
				answer=max(answer,i+cityTrash[cur]);
				dp[cur][i+cityTrash[cur]]=1;
			}
		}
	}
	for(int i=0;i<city[cur].size();i++){
		if(city[cur][i]==prev)continue;
		dfs(city[cur][i],cur);
	}
}

int main() {

	cin >> n >> k;

	for (int i = 0; i < n - 1; i++) {
		cin >> num1 >> num2;
		city[num1].push_back(num2);
		city[num2].push_back(num1);
	}

	for (int i = 1; i <= n; i++) {
		cin >> cityTrash[i];
	}
	dp[0][0]=1;
	dfs(1,0);
	cout<<answer;
	return 0;
}
