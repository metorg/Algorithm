#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[4001][4001];
string st = " ", st2 = " ", tmp, tmp2;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer = 0;

	cin >> tmp >> tmp2;
	st += tmp;
	st2 += tmp2;

	for (int i = 1; i < st.length(); i++) {
		for (int j = 1; j < st2.length(); j++) {
			
			if (st[i] == st2[j]) {
				dp[i][j] = dp[i - 1][j-1] + 1;
				answer = max(dp[i][j], answer);
			}
			
		}
	}

	cout << answer;

}
