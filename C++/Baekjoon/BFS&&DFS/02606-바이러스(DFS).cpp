#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
int n, m;
int visit[102][102];
int visit2[102];
int cnt = -1;
using namespace std;
void dfs(int k) {
	visit2[k] = 1;
	cnt++;
	for (int i = 0;i < n;i++) {
		if (!visit2[i]) {
			if (visit[k][i] == 1) {
				dfs(i);
			}
		}
	}
}
int main() {
	cin >> n;
	cin >> m;
	int num, num2;
	for (int i = 0;i < m;i++) {
		cin >> num >> num2;
		visit[num][num2] = 1;
		visit[num2][num] = 1;
	}
	dfs(1);
	cout << cnt;

}