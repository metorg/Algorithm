#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;
int num;
int num2;
int cnt = 0;
int sum = 0;
int answer[21] = {};

void dfs(int start, int depth,vector<int> v) {
	
	for (int i = 0;i < depth;i++) {
		sum += answer[i];
	}
	if(sum==num2 && depth) {		
		cnt++;
	}
	 sum = 0;
	for (int i = start;i < num;i++) {
		answer[depth] = v[i];
		dfs(i + 1, depth + 1, v);
	}
}
int main() {
	vector<int> v;

	int num3;
		cin >> num>>num2;
		
		for (int i = 0;i < num;i++) {
			cin >> num3;
			v.push_back(num3);
		}
		dfs(0, 0,v);
		cout << cnt;
}

