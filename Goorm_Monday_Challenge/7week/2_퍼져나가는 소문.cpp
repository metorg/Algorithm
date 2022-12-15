#include <iostream>
#include <vector>

using namespace std;

vector<int> v[501];
int visit[501];
	
void dfs(int start){
	for(int i=0;i<v[start].size();i++){
		if(visit[v[start][i]])continue;
		visit[v[start][i]]=1;
		dfs(v[start][i]);
	}
}

int main() {

	int n,m,num1,num2;
	int answer=0;
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		cin>>num1>>num2;
		v[num1].push_back(num2);
		v[num2].push_back(num1);
	}
	visit[1]=1;
	dfs(1);
	
	for(int i=1;i<=n;i++)if(visit[i])answer++;

	cout<<answer;
	
	return 0;
}
