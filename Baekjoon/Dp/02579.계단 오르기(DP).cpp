#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n,num;
int DP[301] = { 0, };
int ar[301] = { 0, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> num;
		ar[i] = num;
	}
	DP[1] = ar[1];
	DP[2] = ar[2]+ar[1];
	
	for (int i = 3;i <= n;i++) {
		DP[i] = max((DP[i-2]+ar[i]),(ar[i]+ar[i-1]+DP[i-3]));
	}
	
	cout << DP[n];
}