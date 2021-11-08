#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int n,num;
int dp[1001];
int arr[1001];
int answer = 0;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	
	//top_down
	/*for (int i = n-2; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[i])dp[i] = max(dp[i], dp[j] + arr[i]);
		}

	}*/

	//bottom_up
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i])dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		answer = max(answer, dp[i]);
	}
	
	cout << answer;

}