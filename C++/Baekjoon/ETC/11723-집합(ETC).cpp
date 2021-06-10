#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<set>

using namespace std;

int S[21];
int n, num;
string ch;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> ch;
		if (ch == "all")fill(S, S + 21, 1);
		else if (ch[0] == 'e') memset(S, 0, sizeof(S));
		else {
			cin >> num;
			if (ch[0] == 'a')S[num] = 1;
			else if (ch[0] == 'r')S[num] = 0;
			else if (ch[0] == 'c') cout << S[num] << '\n';
			else if (ch[0] == 't') S[num] ^= 1;
		}
	}

}