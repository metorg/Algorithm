#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>

using namespace std;

int dp[100002];
int answer = -1e9;
vector<int> v;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)cin >> dp[i];


    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i] + dp[i - 1], dp[i]);
        answer = max(dp[i], answer);
    }

    cout << answer;

}
