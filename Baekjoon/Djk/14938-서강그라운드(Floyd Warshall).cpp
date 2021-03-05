#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
#include<set>

using namespace std;

int a, b, c;
int d, e, f;
int road[101][101];
int item[16];
int mcnt = 0;
int main() {

	ios::sync_with_stdio(0);
	cin >> a >> b >> c;
	for (int i = 1;i <= a;i++) {
		cin >> item[i];
	}
	for (int i = 1;i <= a;i++) {
		for (int j = 1;j <= a;j++) {
			road[i][j] = 100;
		}
		road[i][i] = 0;
	}
	

	for (int i = 0;i < c;i++) {
		cin >> d >> e >> f;
		road[d][e] = f;
		road[e][d] = f;
	}
	for (int k = 1;k <= a;k++) 
		for (int i =1;i <= a;i++) 
			for (int j = 1;j <= a;j++) 
				if (road[i][k] + road[k][j] < road[i][j]) road[i][j] = road[i][k] + road[k][j];
						
	
	for (int i = 1;i <= a;i++) {
		int cnt = 0;
		for (int j = 1;j <= a;j++) {
			if (road[i][j] <= b) cnt += item[j];
		}
		mcnt = max(mcnt, cnt);
	}
	cout << mcnt;


}